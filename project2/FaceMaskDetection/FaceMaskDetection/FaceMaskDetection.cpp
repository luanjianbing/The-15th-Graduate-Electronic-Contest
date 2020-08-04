#include "FaceMaskDetection.h"

FaceMaskDetection::FaceMaskDetection(QWidget *parent)
	: QWidget(parent)
{
	// 不显示标题栏
	this->setWindowFlags(Qt::FramelessWindowHint);

	ui.setupUi(this);

	// 有类似于 ui.xxx->setxxx 放到 ui.setupUi(this) 前会报错
	// 菜单初始化
	menuInit();

	// 打开timerForDataTime
	dateTimeInit();

	// ssd初始化
	solve = new Solution();
	solve->initialParam();

	// 启动Camera
	myCamera.camStart();

	//// 下方记录容器4个
	//vectKnownRecord.resize(4);

	// chart
	//lastData.resize(maxChartAxisXSize, maxNotWornMaskNum / 2);	// 初始化表格数据
	lastData.resize(maxChartAxisXSize);
	for (int i = 0; i < maxChartAxisXSize; ++i)
	{
		lastData[i] = rand() % maxNotWornMaskNum;	// 给个随机数初始化
	}
	countChartInit();
}

void FaceMaskDetection::menuInit()
{
	setUpMenu = new QMenu();

	// 添加启动事件
	QAction *startAction = new QAction(setUpMenu);
	startAction->setIcon(QIcon("./icon/run.png"));
	startAction->setText(tr("  启动"));
	setUpMenu->addAction(startAction);
	// 添加关闭事件
	QAction *closeAction = new QAction(setUpMenu);
	closeAction->setIcon(QIcon("./icon/close.png"));
	closeAction->setText(tr("  关闭"));
	setUpMenu->addAction(closeAction);
	// 添加注册事件
	QAction *registerAction = new QAction(setUpMenu);
	registerAction->setIcon(QIcon("./icon/register.png"));
	registerAction->setText(tr("  注册"));
	setUpMenu->addAction(registerAction);
	// 添加信息查询事件
	QAction *infoQueryAction = new QAction(setUpMenu);
	infoQueryAction->setIcon(QIcon("./icon/query.png"));
	infoQueryAction->setText(tr("  信息查询"));
	setUpMenu->addAction(infoQueryAction);

	// 设置菜单
	setUpMenu->setWindowFlags(setUpMenu->windowFlags() | Qt::FramelessWindowHint);
	setUpMenu->setAttribute(Qt::WA_TranslucentBackground);
	setUpMenu->setStyleSheet(" QMenu {border-radius:5px;font-family:'Arial';font-size:16px;}"
		" QMenu::item {height:28px; width:120px;padding-left:25px;border: 1px solid none;}"
		"QMenu::item:selected {background-color:rgb(0,120,215);\
							padding-left:25px;border: 1px solid rgb(65,173,255);}");
	ui.buttonMenu->setMenu(setUpMenu);

	// 对应动作Action链接
	connect(startAction, SIGNAL(triggered()), this, SLOT(onMenuActionRunTriggered()));
	connect(closeAction, SIGNAL(triggered()), this, SLOT(onMenuActionCloseTriggered()));
	connect(registerAction, SIGNAL(triggered()), this, SLOT(onMenuActionRegisterTriggered()));
	connect(infoQueryAction, SIGNAL(triggered()), this, SLOT(onMenuActionInfoQueryTriggered()));
}

void FaceMaskDetection::cameraShot()
{
	//clock_t t = clock();

	cv::Mat curImg;
	clonePic(curImg);

	QImage res(curImg.data, curImg.cols, curImg.rows, curImg.step, QImage::Format_RGB888);
	ui.labelVideoStream->setPixmap(QPixmap::fromImage(res).scaled(ui.labelVideoStream->width(), ui.labelVideoStream->height(), Qt::KeepAspectRatio));

	//std::cout << ((double)clock() - t) / CLOCKS_PER_SEC << std::endl;
}

void FaceMaskDetection::clonePic(cv::Mat &dst)
{
	try
	{

		cv::Mat imgGet;
		//myCamera.frame.copyTo(dst);
		myCamera.getImage(imgGet);
		//cv::flip(dst, dst, 1);	// 翻转(本机Camera需要)
		dst = imgGet.clone();

		
		//cv::cvtColor(dst, dst, cv::COLOR_BGR2RGB);	// 颜色转换(本机Camera需要)
		maskDetectCount = 0;
		if (maskDetectCount > 0)	// maskDetectCount * 10ms进行一次mask detect
		{
			maskDetectCount--;

			for (int i = 0; i < lastMaskDetectList.size(); ++i)
			{
				cv::Size sizeName = cv::getTextSize(lastNameVect[i], cv::FONT_HERSHEY_SIMPLEX, 1, 1, 0);
				cv::Rect rectName = cv::Rect(lastMaskDetectList[i]._faceLoc);
				rectName.y -= sizeName.height;
				rectName.height = sizeName.height;
				//rectName.width = sizeName.width;
				
				

				if (lastMaskDetectList[i]._faceCla == 0) {
					rectangle(dst, rectName, cv::Scalar(0, 0, 255), cv::FILLED);
					rectangle(dst, cv::Rect(lastMaskDetectList[i]._faceLoc), cv::Scalar(0, 0, 255), 2);
				}
				else {
					rectangle(dst, rectName, cv::Scalar(255, 0, 0), cv::FILLED);
					rectangle(dst, cv::Rect(lastMaskDetectList[i]._faceLoc), cv::Scalar(255, 0, 0), 2);
				}
				putTextZH(dst, lastNameVectGBK[i].c_str(), cv::Point(rectName.x, rectName.y), cv::Scalar(255, 255, 255), 20, "Arial");
			}
		}
		else
		{
			

			std::vector<ObjInfo> vReList;	// 这个里面用来返回多个人脸信息
			//std::thread t_detect(&Solution::ssdFaceMaskDetect, std::bind(std::ref(dst), std::ref(vReList)), &solve);
			//std::thread t_detect(&Solution::ssdFaceMaskDetect, &dst, &vReList);
			//t_detect.join();
			solve->ssdFaceMaskDetect(dst, vReList);	// 1个人脸的话vReList.size() == 1;
			cv::cvtColor(dst, dst, cv::COLOR_BGR2RGB);	// 颜色转换(本机Camera需要)
			cv::Mat dstCopy = dst.clone();
			lastMaskDetectList = vReList;

			int curSize = vReList.size();

			std::vector<QImage> headImg(curSize);
			std::vector<std::string> name(curSize, "");
			std::vector<std::string> nameGBK(curSize, "");
			std::vector<bool> status(curSize, 0);

			bool firstRes = solve->extractFaceFeature(dst, vReList, nameGBK);

			for (int i = 0; i < curSize; ++i)
			{
				//// 人脸比对测试(TODO)
				////solve->readFeatureCSV();	// 读取人脸特侦信息
				//cv::Mat face = dst(cv::Rect(vReList[i]._faceLoc));
				//solve->extractFaceFeature(face, nameGBK[i]);
				//// 这里通过QString转换一下编码问题
				QString str = QString::fromLocal8Bit(nameGBK[i].c_str());	
				//if (nameGBK.size() == 2)
				//{
				//	nameGBK[0] = "zgh";
				//	nameGBK[1] = "ljb";
				//}
				name[i]= str.toStdString();
				

				cv::Rect rect, resizeRect;
				rect = cv::Rect(vReList[i]._faceLoc);
				rectCenterScale(rect, resizeRect, reScale);	// 扩大坐标范围

				cv::Mat cut = dstCopy(resizeRect);	
				headImg[i] = QImage(cut.data, cut.cols, cut.rows, cut.step, QImage::Format_RGB888);

				cv::Size sizeName = cv::getTextSize(name[i], cv::FONT_HERSHEY_SIMPLEX, 1, 1, 0);
				cv::Rect rectName = cv::Rect(vReList[i]._faceLoc);
				rectName.y -= sizeName.height;
				rectName.height = sizeName.height;
				//rectName.width = sizeName.width;
				
				

				if (vReList[i]._faceCla == 0) {
					rectangle(dst, rectName, cv::Scalar(0, 0, 255), cv::FILLED);
					rectangle(dst, cv::Rect(vReList[i]._faceLoc), cv::Scalar(0, 0, 255), 2);
					status[i] = 1;
				}
				else {
					rectangle(dst, rectName, cv::Scalar(255, 0, 0), cv::FILLED);
					rectangle(dst, cv::Rect(vReList[i]._faceLoc), cv::Scalar(255, 0, 0), 2);
					status[i] = 0;
				}
				putTextZH(dst, nameGBK[i].c_str(), cv::Point(rectName.x, rectName.y), cv::Scalar(255, 255, 255), 20, "Arial");
			
			}
			lastNameVectGBK.clear();
			nameGBK.swap(lastNameVectGBK);

			//if (firstRes)
			updateCount--;
			if (updateCount == 0) {
				updateDisplay(headImg, name, status, firstRes);	// 更新显示
				updateCount = 20;
			}
		

			maskDetectCount = 5;	// 赋回原计数
		}
	}
	catch (const std::exception&e)
	{
		std::cout << e.what() << std::endl;
	}
}

void FaceMaskDetection::updateDisplay(std::vector<QImage> &headImg, std::vector<std::string> &name, std::vector<bool> &status, bool startUpdate)
{

	QDateTime dt = QDateTime::currentDateTime();
	QString dtStr = dt.toString("MM-dd hh:mm:ss");

	bool isNeedUpdate = false;
	// 首先通过姓名判断是否要刷新
	if (startUpdate) {
		if (name.size() != lastNameVect.size()) isNeedUpdate = true;
		else
		{
			int i = 0;
			for (; i < name.size(); ++i) {
				if (name[i] != lastNameVect[i])
					break;
			}
			if (i == name.size()) { 
				isNeedUpdate = false; 
			}
			else isNeedUpdate = true;
			
		
		}
	//else isNeedUpdate = false;
	}
	else
	{
		lastNameVect.clear();
		lastStatusVect.clear();
		name.swap(lastNameVect);
		status.swap(lastStatusVect);
	}
	// 然后通过状态判断是否要刷新
	if (isNeedUpdate == false)
	{
		int i = 0;
		for (; i < status.size(); ++i) {
			if (status[i] != lastStatusVect[i])
				break;
		}
		if (i == status.size()) {
			isNeedUpdate = false;
		}
		else isNeedUpdate = true;
	}
	//isNeedUpdate = false;
	std::cout << "startUpdate : "<< startUpdate <<"isNeedUpdate : " << isNeedUpdate << std::endl;
	if (isNeedUpdate == false)
	{
		// 
		//lastNameVect.clear();
		//lastStatusVect.clear();
		//name.swap(lastNameVect);
		//status.swap(lastStatusVect);
	}
	else
	{
		
		try
		{

		
		for (int i = 0; i < status.size(); i++)
		{
			if (name[i] == "Unknown")
			{
				if (status[i] == 0)	// 未佩戴口罩
				{
					// 预警
					//QString isOnMask = "未佩戴口罩";
					QListWidgetItem *list = new QListWidgetItem();
					QString perItem = QString("%1      %2      %3").arg(dtStr).arg("Unknown").arg("未佩戴口罩");
					// (TODO)完善信息
					list->setText(perItem);
					ui.listWidgetLog->addItem(list);

					// 未带口罩报警
					ui.labelUnknownImage->setPixmap(QPixmap::fromImage(headImg[i]).scaled(ui.labelUnknownImage->width(), ui.labelUnknownImage->height(), Qt::KeepAspectRatio));
					QString dtStrUnknown = dt.toString("yyyy-MM-dd hh:mm:ss");
					ui.labelUnknownTimeDis->setText(dtStrUnknown);
					ui.labelUnknownMaskDis->setText("无");

					notWornMaskNum++;
				}
				else  // 佩戴口罩
				{

				}
			}
			else	// 非陌生人
			{
				// 下方记录显示
				//updateKnownRecord(headImg[i], name[i], status[i]);	// 更新下方记录显示
				if (status[i] == 0)	// 未佩戴口罩
				{
					updateKnownRecord(headImg[i], name[i], status[i]);
					// 预警
					//QString isOnMask = "未佩戴口罩";
					QListWidgetItem *list = new QListWidgetItem();
					QString perItem = QString("%1      %2      %3").arg(dtStr).arg(QString::fromStdString(name[i])).arg("未佩戴口罩");
					// (TODO)完善信息
					list->setText(perItem);
					ui.listWidgetLog->addItem(list);

					notWornMaskNum++;

				}
				else  // 佩戴口罩
				{

				}
			}

		}
		// 调整预警信息Item允许显示个数
		if (ui.listWidgetLog->count() > logItemNum)
		{
			if (ui.listWidgetLog->count() == logItemNum + 1) {
				QListWidgetItem *tmp = ui.listWidgetLog->takeItem(0);
				delete tmp;
			}
			else {
				for (int i = ui.listWidgetLog->count() - logItemNum; i > 0; --i)
				{
					QListWidgetItem *tmp = ui.listWidgetLog->takeItem(i);
					delete tmp;
				}
			}
		}

		updateDataInDataBase(headImg, name, status);	// 更新数据库信息

		lastNameVect.clear();
		lastStatusVect.clear();
		name.swap(lastNameVect);
		status.swap(lastStatusVect);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

}

void FaceMaskDetection::updateKnownRecord(QImage &curImg, const std::string curName, const bool curStatus)
{
	KnownRecord kr(curImg, curName, curStatus);

	if (curKnownRecordSize > 4)	// 满4个
	{
		if (vectKnownRecord[3].curName == kr.curName)
			return;
		for (int i = 0; i < 3; ++i)
		{
			vectKnownRecord[i] = vectKnownRecord[i + 1];
		}
		vectKnownRecord[3] = kr;

		ui.labelImage_1->setPixmap(QPixmap::fromImage(vectKnownRecord[0].curImg).scaled(ui.labelImage_1->width(), ui.labelImage_1->height(), Qt::KeepAspectRatio));
		ui.labelNameDis_1->setText(vectKnownRecord[0].curName);
		ui.labelMaskDis_1->setText(vectKnownRecord[0].curStatus);

		ui.labelImage_2->setPixmap(QPixmap::fromImage(vectKnownRecord[1].curImg).scaled(ui.labelImage_2->width(), ui.labelImage_2->height(), Qt::KeepAspectRatio));
		ui.labelNameDis_2->setText(vectKnownRecord[1].curName);
		ui.labelMaskDis_2->setText(vectKnownRecord[1].curStatus);

		ui.labelImage_3->setPixmap(QPixmap::fromImage(vectKnownRecord[2].curImg).scaled(ui.labelImage_3->width(), ui.labelImage_3->height(), Qt::KeepAspectRatio));
		ui.labelNameDis_3->setText(vectKnownRecord[2].curName);
		ui.labelMaskDis_3->setText(vectKnownRecord[2].curStatus);

		ui.labelImage_4->setPixmap(QPixmap::fromImage(vectKnownRecord[3].curImg).scaled(ui.labelImage_4->width(), ui.labelImage_4->height(), Qt::KeepAspectRatio));
		ui.labelNameDis_4->setText(vectKnownRecord[3].curName);
		ui.labelMaskDis_4->setText(vectKnownRecord[3].curStatus);
	}
	else	// 小于4个
	{
		if (vectKnownRecord.size() > 0)
		{
			if (vectKnownRecord.back().curName == kr.curName)
				return;
		}
		switch (vectKnownRecord.size())
		{
		case 0:
		{
			ui.labelImage_1->setPixmap(QPixmap::fromImage(kr.curImg).scaled(ui.labelImage_1->width(), ui.labelImage_1->height(), Qt::KeepAspectRatio));
			ui.labelNameDis_1->setText(kr.curName);
			ui.labelMaskDis_1->setText(kr.curStatus);
			break;
		}
		case 1:
		{
			ui.labelImage_2->setPixmap(QPixmap::fromImage(kr.curImg).scaled(ui.labelImage_2->width(), ui.labelImage_2->height(), Qt::KeepAspectRatio));
			ui.labelNameDis_2->setText(kr.curName);
			ui.labelMaskDis_2->setText(kr.curStatus);
			break;
		}
		case 2:
		{
			ui.labelImage_3->setPixmap(QPixmap::fromImage(kr.curImg).scaled(ui.labelImage_3->width(), ui.labelImage_3->height(), Qt::KeepAspectRatio));
			ui.labelNameDis_3->setText(kr.curName);
			ui.labelMaskDis_3->setText(kr.curStatus);
			break;
		}
		case 3:
		{
			ui.labelImage_4->setPixmap(QPixmap::fromImage(kr.curImg).scaled(ui.labelImage_4->width(), ui.labelImage_4->height(), Qt::KeepAspectRatio));
			ui.labelNameDis_4->setText(kr.curName);
			ui.labelMaskDis_4->setText(kr.curStatus);
			break;
		}
		default:
			break;
		}
		vectKnownRecord.push_back(kr);
		curKnownRecordSize++;
	}
}

void FaceMaskDetection::updateDataInDataBase(std::vector<QImage> &headImg, std::vector<std::string> &name, std::vector<bool> &status)
{
	std::vector<std::vector<std::string>> toSaveVect;
	toSaveVect.resize(name.size());
	for (int i = 0; i < toSaveVect.size(); ++i)
	{
		toSaveVect[i].resize(4);
	}
	std::string timeStr = dateTime.toString("yyyy-MM-dd hh:mm:ss").toStdString();
	std::string pathImg = "./image/";
	pathImg.append(dateTime.toString("yyyyMMdd_hhmmss").toStdString()).append("_");
	for (int i = 0; i < toSaveVect.size(); ++i)
	{
		toSaveVect[i][0] = timeStr;
		toSaveVect[i][1] = name[i];
		toSaveVect[i][2] = status[i] == true ? "1" : "0";
		toSaveVect[i][3] = pathImg.append(std::to_string(i));
	}
	// 开启线程存储图片(这里如果上面不断更新的话应该是有问题的，就那么几个核，开不了那么多线程)
	//auto t_writeImage = [=] {
		//isOnSavingImg = true;
		for (int i = 0; i < toSaveVect.size(); ++i)
		{
			headImg[i].save(QString::fromStdString(toSaveVect[i][3]), "JPG");	// 这里保存的图像用画图可以打开
		}
		// 更新数据库表
		sql_conn.insertTableLog(toSaveVect);
	//};
	//std::thread cthread(t_writeImage);
	////cthread.detach();
	//cthread.join();	// detach会有点问题，暂时先阻塞
}

// 菜单启动动作
void FaceMaskDetection::onMenuActionRunTriggered()
{

	if (timerForCamLive.isActive() == false) 
	{
		timerForCamLive.start(20);
		connect(&timerForCamLive, SIGNAL(timeout()), this, SLOT(cameraShot()));
	}
}

// 菜单关闭动作
void FaceMaskDetection::onMenuActionCloseTriggered()
{

	if (timerForCamLive.isActive() == true)
	{
		timerForCamLive.stop();
		disconnect(&timerForCamLive, SIGNAL(timeout()), this, SLOT(cameraShot()));
		ui.labelVideoStream->clear();
		//myCamera.camStop();
	}
	else 
	{
		this->close();
	}
}

// 菜单注册动作
void FaceMaskDetection::onMenuActionRegisterTriggered()
{
	// 注册时先把定时器关掉
	if (timerForCamLive.isActive() == true)
	{
		timerForCamLive.stop();
		disconnect(&timerForCamLive, SIGNAL(timeout()), this, SLOT(cameraShot()));
		ui.labelVideoStream->clear();
	}
	//// 关闭cam
	//myCamera.camStop();
	
	RegisterFace *registerFace = new RegisterFace(&myCamera);
	// 设置子窗口属性，在子窗口关闭之后，释放子窗口的资源(释放指针)
	registerFace->setAttribute(Qt::WA_DeleteOnClose);
	registerFace->show();
}

// 菜单信息查询动作
void FaceMaskDetection::onMenuActionInfoQueryTriggered()
{
	InfoQuery *infoQuery = new InfoQuery();
	// 设置子窗口属性，在子窗口关闭之后，释放子窗口的资源(释放指针)
	infoQuery->setAttribute(Qt::WA_DeleteOnClose);
	infoQuery->show();
}

// chart init
void FaceMaskDetection::countChartInit()
{	
	m_chart = new QChart();
	m_series = new QLineSeries(m_chart);

	qint64 curTimeTotalMSecond = QDateTime::currentMSecsSinceEpoch();	// 获取迄今为止的ms数
	// 计算当天已经的ms数
	qint64 todayTimeTotalMSecond = QTime::currentTime().hour() * 3600 * 1000 + QTime::currentTime().minute() * 60 * 1000
		+ QTime::currentTime().second() * 1000 + QTime::currentTime().msec();
	// 添加maxChartAxisXSize个点到折线中
	for (int i = maxChartAxisXSize; i > 0; --i)
	{
		m_series->append(curTimeTotalMSecond - 86400000 * i - todayTimeTotalMSecond, lastData[maxChartAxisXSize - i]);
	}
	//m_series->append(curTimeTotalMSecond - 86400000 * 5 - todayTimeTotalMSecond
	//	, 0);
	//m_series->append(curTimeTotalMSecond - 86400000 * 4 - todayTimeTotalMSecond
	//	, maxNotWornMaskNum / 2);
	//m_series->append(curTimeTotalMSecond - 86400000 * 3 - todayTimeTotalMSecond
	//	, 0);
	//m_series->append(curTimeTotalMSecond - 86400000 * 2 - todayTimeTotalMSecond
	//	, maxNotWornMaskNum / 2);
	//m_series->append(curTimeTotalMSecond - 86400000 - todayTimeTotalMSecond
	//	, 0);

	//m_series->setName("test");
	//m_series->setVisible(true);
	//m_series->setPointLabelsFormat("(@xPoint,@yPoint)");
	//m_series->setPointLabelsVisible(true);
	m_chart->addSeries(m_series);
	m_series->setUseOpenGL(true);	// 加速

	m_chart->setTheme(QChart::ChartThemeDark);	// 设置主题

	// 时间X轴
	QDateTimeAxis *axisX = new QDateTimeAxis();
	axisX->setFormat("MM-dd");	// 设置格式
	QDateTime curDateInit = QDateTime::currentDateTime();	// 获取当前时间
	axisX->setMin(curDateInit.addDays(-maxChartAxisXSize).addMSecs(-todayTimeTotalMSecond));	// 设置时间X轴最小值
	axisX->setMax(curDateInit.addDays(-1).addMSecs(-todayTimeTotalMSecond));	// 设置时间X轴最大值
	axisX->setTickCount(maxChartAxisXSize);	// 设置几格
	// 值Y轴
	QValueAxis *axisY = new QValueAxis();
	axisY->setLabelFormat("%d");
	axisY->setRange(0, maxNotWornMaskNum);	// 设置范围
	axisY->setTickCount(maxChartAxisXSize);	// 设置几格
	axisY->setGridLineVisible(false);	// 取消y轴网格线

	m_chart->setAxisX(axisX, m_series);
	m_chart->setAxisY(axisY, m_series);
	m_chart->legend()->hide();	// 隐藏图例

	ui.widgetChart->setChart(m_chart);
}

//// 数据更新
//void FaceMaskDetection::updateCountChart()
//{
//
//}

// 日期时间初始化
void FaceMaskDetection::dateTimeInit()
{
	if (timerForDataTime.isActive() == false) {
		timerForDataTime.start(1000);	// 1s
		connect(&timerForDataTime, SIGNAL(timeout()), this, SLOT(onUpdateDateTime()));
	}
}

// 日期时间显示更新
void FaceMaskDetection::onUpdateDateTime()
{
	dateTime = QDateTime::currentDateTime();
	dataTimeStr = dateTime.toString("yyyy-MM-dd hh:mm:ss ddd");
	ui.labelTime->setText(dataTimeStr);

	if (dateTime.time().toString("hh:mm:ss") == "00:00:01")
	{
		qint64 curTimeTotalMSecond = QDateTime::currentMSecsSinceEpoch();
		//// forTest
		//qint64 todatTimeTotalMSecond = QTime::currentTime().hour() * 3600 * 1000 + QTime::currentTime().minute() * 60 * 1000
		//	+ QTime::currentTime().second() * 1000 + QTime::currentTime().msec();
		qint64 todatTimeTotalMSecond = 1 * 1000;
		// 更新X轴
		//// forTest
		//m_chart->axisX()->setMin(QDateTime::currentDateTime().addDays(-maxChartAxisXSize + 1).addMSecs(-todatTimeTotalMSecond));
		//m_chart->axisX()->setMax(QDateTime::currentDateTime().addDays(0).addMSecs(-todatTimeTotalMSecond));
		m_chart->axisX()->setMin(QDateTime::currentDateTime().addDays(-maxChartAxisXSize).addMSecs(-todatTimeTotalMSecond));
		m_chart->axisX()->setMax(QDateTime::currentDateTime().addDays(-1).addMSecs(-todatTimeTotalMSecond));
		// 更新数据
		//// forTest
		//m_series->removePoints(0, 1);
		//m_series->append(curTimeTotalMSecond - todatTimeTotalMSecond, notWornMaskNum);
		m_series->removePoints(0, 1);
		m_series->append(curTimeTotalMSecond - todatTimeTotalMSecond - 86400000, notWornMaskNum);
		// (TODO)
		// 这里要不要把数据更新到lastData中？
	}
}

void FaceMaskDetection::rectCenterScale(cv::Rect &rect, cv::Rect &resizeRect, const double scale)
{
	if (scale < 1) return;	// 当前只允许放大
	double tmp = (scale - 1) / 2.0;
	resizeRect = rect;

	resizeRect.x -= resizeRect.width * tmp;
	resizeRect.y -= resizeRect.height * tmp;
	resizeRect.width *= scale;
	resizeRect.height *= scale;

	if (resizeRect.x < 0) resizeRect.x = 0;
	if (resizeRect.y < 0) resizeRect.y = 0;
	if (resizeRect.x + resizeRect.width > CameraSize.width) resizeRect.width = CameraSize.width - resizeRect.x;
	if (resizeRect.y + resizeRect.height > CameraSize.height) resizeRect.height = CameraSize.height - resizeRect.y;
}

FaceMaskDetection::~FaceMaskDetection()
{
	// 删除菜单
	delete setUpMenu;
	//// 删除myCamera
	//delete myCamera;
	// 关闭timerForCamLive
	if (timerForCamLive.isActive() == true)
		timerForCamLive.stop();
	// 关闭Camera
	myCamera.camStop();
	// 关闭timerForDataTime
	if (timerForDataTime.isActive() == true)
		timerForDataTime.stop();
	// 删除solve
	delete solve;
	// 删除chart
	delete m_chart;
	// 删除series
	delete m_series;
}
