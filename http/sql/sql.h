#ifndef _SQL_H_
#define _SQL_H_

#include <iostream>
#include <mysql.h>
#include <string>

using namespace std;
class sql{
	public:
		sql(const string &_user,\
    	         const string &_ip,\
				 const string &_passwd,\
				 const string &_db,\
    	         const int &_port);
		//	:user(_user),ip(_ip),passwd(_passwd),db(_db),port(_port);

		int connect();
		int insert(const string &name,\
				    const string &password,\
					const string &id);

		~sql();
	private:
		MYSQL *conn;
		string user;
		string ip;
		string passwd;
		string db;
		int port;
};

#endif
