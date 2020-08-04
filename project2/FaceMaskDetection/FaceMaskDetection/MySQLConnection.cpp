#include "MySQLConnection.h"

MySQLConnection::MySQLConnection()
{
	info.host = HOST_;
	info.user = USER_;
	info.password = PASSWORD_;
	info.database = DATABASE_;
	mysql_conn = mysqlConnect(info);
}

// 连接数据库
MYSQL *MySQLConnection::mysqlConnect(conn_info con) {
	MYSQL *mysql = mysql_init(NULL);	//mysql初始化函数，实例化一个新的对象（NULL为新的对象，否则为初始化以创建的对象)
	if (!mysql_real_connect(mysql, con.host, con.user, con.password, con.database, 3306, NULL, 0)) {	//mysql_real_connect(MYSQL *mysql,const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag)
		std::cout << "Connection MySQL Error" << std::endl;
		exit(1);
	}
	std::cout << "Connection MySQL Success" << std::endl;
	mysql_query(mysql, "set names utf8");		// 需要设置一下
	return mysql;	//返回实例化的对象
}

// 数据库操作
void MySQLConnection::mysqlOperation(char *sql_op) {
	if (mysql_query(mysql_conn, sql_op)) {		//mysql_query()函数为对mysql进行操作，第一个参数为刚才实例化的对象，第二个位需要进行的操作
		printf("MySQL query error : %s", mysql_error(mysql_conn));
		getchar();
		exit(1);
	}
}

// 数据库断开
void MySQLConnection::mysqlDisconnect() {
	mysql_close(mysql_conn);//断开连接
	std::cout << "Disconnect from MySQL" << std::endl;
}

// 查询表格所有数据返回vector
std::vector<std::vector<std::string>> MySQLConnection::tab2Vector(const char * table, const int colNum) {
	char cmd[100];

	MYSQL_RES *res;
	MYSQL_ROW col;

	std::vector<std::vector<std::string>> vect;
	std::vector<std::string> _vect;

	res = NULL;//要先初始化，否则会报错

	strcpy(cmd, "select * from ");
	strcat(cmd, table);		//拼接指令

	mysql_free_result(res);
	mysqlOperation(cmd);
	res = mysql_store_result(mysql_conn);

	while ((col = mysql_fetch_row(res)) != NULL)		// 每一行访问
	{
		for (int i = 0; i < colNum; i++) {
			_vect.push_back(col[i]);
		}
		vect.push_back(_vect);
		for (int i = 0; i < colNum; i++) {
			_vect.pop_back();
		}
	}

	return vect;
}

void MySQLConnection::insertTableWarning(std::vector<std::string> &vect) {

}

void MySQLConnection::insertTableLog(const std::vector<std::vector<std::string>> &vect) {
	for (int i = 0; i < vect.size(); ++i)
	{
		char cmd[500];
		strcpy(cmd, "insert into log (time, name, status, message) values (");
		strcat(cmd, "\"");
		strcat(cmd, vect[i][0].c_str());
		strcat(cmd, "\",");
		strcat(cmd, "\"");
		strcat(cmd, vect[i][1].c_str());
		strcat(cmd, "\",");
		strcat(cmd, "\"");
		strcat(cmd, vect[i][2].c_str());
		strcat(cmd, "\",");
		strcat(cmd, "\"");
		strcat(cmd, vect[i][3].c_str());
		strcat(cmd, "\"");
		//if (i != (vect.size() - 1))	strcat(cmd, "),");
		strcat(cmd, ")");
		mysqlOperation(cmd);
	}
}

MySQLConnection::~MySQLConnection()
{
	mysqlDisconnect();
	//delete mysql_conn;
}