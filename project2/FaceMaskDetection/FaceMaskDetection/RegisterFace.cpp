#include "RegisterFace.h"

RegisterFace::RegisterFace(Camera *cam, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowModality(Qt::ApplicationModal);

	// 不显示标题栏
	this->setWindowFlags(Qt::FramelessWindowHint);

	myCameraRegister = new Camera();
	// 启动Camera
	//myCameraRegister->camStart();
	myCameraRegister = cam;

	// button close
	connect(ui.buttonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));

	// button start record
	connect(ui.buttonStartRecord, SIGNAL(clicked()), this, SLOT(onButtonStartRecordClicked()));

	// 计算人脸放入区域
	faceArea.x = CameraSize.width / 4;
	faceArea.y = CameraSize.height / 4;
	faceArea.width = CameraSize.width / 2;
	faceArea.height = CameraSize.height / 2;
}

// button start record
void RegisterFace::onButtonStartRecordClicked()
{
	// 开始录入信息
	if (ui.lineEditName->text().isEmpty())	// 首先确保已经输入名字
	{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setText("<font color='gray'>Please Input Your Name First!!!</font>");
		//msgBox.setStyleSheet("background:#020d2c");
		msgBox.setStyleSheet("QPushButton { background:#162e6c;color:gray; }");
		msgBox.exec();	// 阻塞显示
	}
	else
	{
		toRegisterUserName = ui.lineEditName->text().toStdString();	// 获取待注册用户姓名
		timerForRegister = new QTimer();	// 
		if (timerForRegister->isActive() == false)
		{
			timerForRegister->start(10);
			connect(timerForRegister, SIGNAL(timeout()), this, SLOT(camShot()));
		}
	}
}

void RegisterFace::camShot()
{
	if (faceImportCnt > 0) {
		faceImportCnt--;
		if (faceImportCnt % 100 == 1) std::cout << "Record face info will be started in " 
			<< faceImportCnt / 100 << " seconds" << std::endl;
	}
	cv::Mat curImg;
	clonePic(curImg);
	cv::rectangle(curImg, cv::Rect(faceArea), cv::Scalar(0, 255, 0), 2);
	if (!faceImportCnt) {	// 清零
		faceImportCnt = -1;
		Solution *s;
		s = new Solution();
		cv::Mat cut = curImg(cv::Rect(faceArea));
		s->extractFaceFeatureAndSave(cut, toRegisterUserName);
		std::cout << "Record face info has finished!!" << std::endl;
		QMessageBox::about(this, "Tips", "<font color='gray'>Record face info has finished!!. Press OK To close.");
	}
	QImage res(curImg.data, curImg.cols, curImg.rows, curImg.step, QImage::Format_RGB888);
	ui.labelVideoStreamRegister->setPixmap(QPixmap::fromImage(res).scaled(ui.labelVideoStreamRegister->width(), ui.labelVideoStreamRegister->height(), Qt::KeepAspectRatio));
}

void RegisterFace::clonePic(cv::Mat &dst)
{
	cv::Mat dstImgGet;
	//myCameraRegister->frame.copyTo(dst);
	myCameraRegister->getImage(dstImgGet);
	//cv::flip(dst, dst, 1);	// 翻转(本机Camera需要)
	dst = dstImgGet.clone();
	cv::cvtColor(dst, dst, cv::COLOR_BGR2RGB);	// 颜色转换(本机Camera需要)
}

// button close
void RegisterFace::onButtonCloseClicked()
{
	myCameraRegister->camStop();
	
	if (timerForRegister->isActive() == true)
		timerForRegister->stop();
	

	this->close();
}

RegisterFace::~RegisterFace()
{
	//delete myCameraRegister;	// 删除会有问题？
	delete timerForRegister;
}