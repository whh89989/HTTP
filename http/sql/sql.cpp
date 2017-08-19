#include "sql.h"
using namespace std;

sql::sql(const string &_user,\
		 const string &_ip,\
		 const string &_passwd,\
		 const string &_db,\
		 const int &_port):user(_user),ip(_ip),passwd(_passwd),\
						  db(_db),port(_port)
{
	conn = mysql_init(NULL);
}

int sql::connect()
{
	if(mysql_real_connect(conn,ip.c_str(),user.c_str(),\
				passwd.c_str(),db.c_str(),port,NULL,0)){
		cout<<"connect success!!!"<<endl;
		return 0;
	}else{
		return 1;
	}
}


int sql::insert(const string &name,\
		        const string &password,\
				const string &id)
{
	//"insert into"
	string sql = "INSERT INTO uers (name, password, id) values ('";
	sql+=name;
	sql+="','";
	sql+=password;
	sql+="','";
	sql+=id;
	sql+="');";
	cout<<sql<<endl;

	int ret = mysql_query(conn,sql.c_str());
	cout<<"ret:"<<ret<<endl;
}
sql::~sql()
{
	mysql_close(conn);
}
