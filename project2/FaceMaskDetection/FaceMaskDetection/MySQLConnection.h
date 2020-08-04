#pragma once
#ifndef MYSQLCONNECTION_H
#define MYSQLCONNECTION_H 

#include <iostream>
#include <vector>

#include <winsock.h>	// 这个要加到mysql头文件前面
#include <mysql.h>

#define HOST_ "localhost"
#define USER_ "root"
#define PASSWORD_ "111111"
#define DATABASE_ "facemaskdatabase"

struct conn_info {
	char *host;
	char *user;
	char *password;
	char *database;
};

class MySQLConnection
{
public:
	MySQLConnection();
	~MySQLConnection();

	// 表格转换成vector
	std::vector<std::vector<std::string>> tab2Vector(const char * table, const int colNum);

	// warning表插入
	void insertTableWarning(std::vector<std::string> &vect);

	// log表插入
	void insertTableLog(const std::vector<std::vector<std::string>> &vect);

private:
	MYSQL *mysql_conn;
	conn_info info;

	// 连接数据库
	MYSQL *mysqlConnect(conn_info con);

	// 数据库操作
	void mysqlOperation(char *sql_op);

	// 数据库断开
	void mysqlDisconnect();
};

#endif // MYSQLCONNECTION_H
