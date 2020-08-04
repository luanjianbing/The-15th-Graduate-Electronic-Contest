#pragma once

#include "stdafx.h"
#include "ui_InfoQuery.h"
#include "MySQLConnection.h"

#include <QLabel>
#include <QSizePolicy>

class InfoQuery : public QWidget
{
	Q_OBJECT

public:
	InfoQuery(QWidget *parent = Q_NULLPTR);
	~InfoQuery();

private:
	Ui::InfoQueryClass ui;

	// 查询已注册用户及名称
	int perColumnDis = 3;
	int perDisW = 180, perDisH = 160;
	std::vector<cv::Mat> hasRegisteredImage;
	std::vector<std::string> hasRegisteredName;
	void queryHasRegisteredUsers();
	void hasRegisteredUsersDisplay();

	void hasRecordListDisplay();

	// 查询数据库中所有记录
	int perColumnRecordDis = 2;
	int perDisRecordW = 700, perDisRecordH = 240;
	MySQLConnection sql_conn;
	std::vector<std::vector<std::string>> recordList;

	private slots:
	
	void onButtonCloseClicked();
	//void onRecordListDisplay(int idx);
};