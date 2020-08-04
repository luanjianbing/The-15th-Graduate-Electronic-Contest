#include "InfoQuery.h"

InfoQuery::InfoQuery(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowModality(Qt::ApplicationModal);

	// 不显示标题栏
	this->setWindowFlags(Qt::FramelessWindowHint);

	// button close
	connect(ui.buttonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));

	// 读取注册用户信息
	queryHasRegisteredUsers();
	// 设置perColumnDis列
	for (int i = 0; i < perColumnDis; ++i)
	{
		ui.gridLayoutRg->setColumnStretch(i, 1);
	}
	// 显示注册用户信息
	hasRegisteredUsersDisplay();

	// 读取数据先
	recordList = sql_conn.tab2Vector("log", 5);	// 首先读取所有记录

	// 显示所有记录
	hasRecordListDisplay();
	// connect tab changed
	//connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onRecordListDisplay(int)));
}

void InfoQuery::queryHasRegisteredUsers()
{
	std::string pattern_jpg;
	std::vector<cv::String> image_files;
	pattern_jpg = "./featureFace/*.png";
	cv::glob(pattern_jpg, image_files);
	// 初始化大小
	hasRegisteredImage.resize(image_files.size());
	hasRegisteredName.resize(image_files.size());
	// 读取图像以及名称
	for (int ii = 0; ii<image_files.size(); ii++)
	{
		// 14为前面文件名字符穿长度，即名字信息从哪里开始
		int nameLength = image_files[ii].find(".png") - 14;
		//std::cout << image_files[ii].substr(14, nameLength) << std::endl;
		hasRegisteredName[ii] = image_files[ii].substr(14, nameLength);
		hasRegisteredImage[ii] = imread(image_files[ii]);
	}
}

void InfoQuery::hasRegisteredUsersDisplay()
{
	int sizeAll = hasRegisteredName.size() / perColumnDis + 1;
	ui.scrollAreaWidgetContentsRg->setMinimumHeight(sizeAll * perDisH + 100);
	for (int i = 0; i < hasRegisteredName.size(); ++i)
	{
		QLabel *labelWidget = new QLabel();
		labelWidget->setFixedSize(perDisW + 60, perDisH + 10);
		labelWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		labelWidget->setFrameShape(QFrame::WinPanel);
		QGridLayout *gridLayoutLabelWidget = new QGridLayout(labelWidget);
		QLabel *labelImg = new QLabel();
		QImage thisImg(hasRegisteredImage[i].data, hasRegisteredImage[i].cols, hasRegisteredImage[i].rows, hasRegisteredImage[i].step, QImage::Format_RGB888);
		labelImg->setPixmap(QPixmap::fromImage(thisImg).scaled(perDisW, perDisH, Qt::KeepAspectRatio));
		QLabel *labelName = new QLabel();
		labelName->setText(QString::fromStdString(hasRegisteredName[i]));
		gridLayoutLabelWidget->addWidget(labelImg, 0, 0);
		gridLayoutLabelWidget->addWidget(labelName, 0, 1);
		ui.gridLayoutRg->addWidget(labelWidget);
	}
}

void InfoQuery::hasRecordListDisplay()
{
	int sizeAll = recordList.size() + 1;
	ui.scrollAreaWidgetContentsRd->setMinimumHeight(sizeAll * perDisRecordH + 100);
	for (int i = 0; i < recordList.size(); ++i)
	{
		QLabel *labelWidget = new QLabel();
		labelWidget->setFixedSize(perDisRecordW + 60, perDisRecordH + 10);
		labelWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		labelWidget->setFrameShape(QFrame::WinPanel);
		QGridLayout *gridLayoutLabelWidget = new QGridLayout(labelWidget);
		QLabel *labelImg = new QLabel();
		labelImg->setFixedSize((perDisRecordW + 60) / 4, perDisRecordH);
		labelImg->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		cv::Mat tmpImg = cv::imread(recordList[i][4]);
		cv::cvtColor(tmpImg, tmpImg, CV_RGB2BGR);
		QImage thisImg(tmpImg.data, tmpImg.cols, tmpImg.rows, tmpImg.step, QImage::Format_RGB888);
		labelImg->setPixmap(QPixmap::fromImage(thisImg).scaled(labelImg->width(), labelImg->height(), Qt::KeepAspectRatio));

		QLabel *labelNameText = new QLabel();
		labelNameText->setText("姓名 : ");
		QLabel *labelName = new QLabel();
		labelName->setText(QString::fromStdString(recordList[i][2]));
		QLabel *labelTimeText = new QLabel();
		labelTimeText->setText("时间 : ");
		QLabel *labelTime = new QLabel();
		labelTime->setText(QString::fromStdString(recordList[i][1]));
		QLabel *labelStatusText = new QLabel();
		labelStatusText->setText("状态 : ");
		QLabel *labelStatus = new QLabel();
		QString tmpStatus = recordList[i][3] == "0" ? "未佩戴口罩" : "已佩戴口罩";
		labelStatus->setText(tmpStatus);
		
		gridLayoutLabelWidget->addWidget(labelImg, 0, 0);
		gridLayoutLabelWidget->addWidget(labelNameText, 0, 1);
		gridLayoutLabelWidget->addWidget(labelName, 0, 2);
		gridLayoutLabelWidget->addWidget(labelTimeText, 0, 3);
		gridLayoutLabelWidget->addWidget(labelTime, 0, 4);
		gridLayoutLabelWidget->addWidget(labelStatusText, 1, 1);
		gridLayoutLabelWidget->addWidget(labelStatus, 1, 2);
		ui.gridLayoutRd->addWidget(labelWidget);
	}
}

//void InfoQuery::onRecordListDisplay(int idx)
//{
//	std::cout << idx << std::endl;
//	
//
//}

void InfoQuery::onButtonCloseClicked()
{
	this->close();
}

InfoQuery::~InfoQuery()
{
	
}