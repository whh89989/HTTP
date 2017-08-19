#include "sql.h"
using namespace std;

int main()
{
	sql obj("root","127.0.0.1","","http",3306);
	obj.connect();
	obj.insert("lisi","lisi1234","0");
	return 0;
}
