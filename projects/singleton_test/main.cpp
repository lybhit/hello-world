#include <iostream>
#include <boost/pool/detail/singleton.hpp>

using boost::details::pool::singleton_default;
using namespace std;

class SqlDB_t
{
public:
  void connect()
  {cout << "connect db" << endl;}
  void exec(const char* sqlstr)
  {cout << "exec insert/update/delete :" << sqlstr << endl;}
  void query(const char *sqlstr)
  {cout << "exec select " << sqlstr << endl;}
};
typedef singleton_default<SqlDB_t> SqlDB;

int main(int argc, char **argv) {
  cout << "main() start" << endl;
  SqlDB::instance().connect();
  SqlDB::instance().exec("create table goods (int id, varchar name(20))");
  SqlDB::instance().exec("insert into goods values (101, 'wii')");
  SqlDB::instance().query("select * from goods");
  
  cout << "main() finish" << endl;
  
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
