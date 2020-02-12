#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <mysql/mysql.h>
#include <eigen3/Eigen/Dense>

using namespace std;

int main(int argc, char **argv) {
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;
  char *server = "localhost";
  char *user = "root";
  char *password = "123456";
  char *database = "suirui_powerstation";
  conn = mysql_init(NULL);
  
  if(!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)){
    cout << mysql_error(conn) << endl;
    return -1;
  }
  
  if(mysql_query(conn, "show tables")){
    cout << mysql_error(conn);
    return -1;
  }
  
  res = mysql_use_result(conn);
  cout << "MySQL Tables in mysql database: \n";
  
  while((row = mysql_fetch_row(res)) != NULL)
    cout << row[0] << endl;
  
  mysql_query(conn, "set names gbk");
  
  if(mysql_query(conn, "SELECT * FROM rb_topologypoint"))
  {
    cout << mysql_error(conn) << endl;
    return -1;
  }
  
  if(!(res = mysql_store_result(conn)))
  {
    cout << "could not get result from " << mysql_error(conn) << endl;
    return -1;
  }
  
  cout << "number of dataline returned: " << mysql_error(conn) << endl;
  
  char *str_field[32];
  
  for(int i = 0; i < 4; ++i)
  {
    str_field[i] = mysql_fetch_field(res)->name;
  }
  
  for(int i = 0; i < 4; ++i)
  {
    cout << str_field[i] << endl;
  }
  
  vector<pair<string, Eigen::Vector2f>> p_set;
  while(row = mysql_fetch_row(res))
  {
    cout << row[0] << "\t" << row[1] << '\t' << row[2] << '\t' << row[3] << endl;
    
//     float x = (float)row[2];
//     float y = (float)row[3];
//     
//     Eigen::Vector2f point(x, y);
//     
//     p_set.emplace_back(make_pair<string, Eigen::Vector2f>(row[0], point));
//     cout << p_set.back().second << endl;
  }
  
  mysql_free_result(res);
  mysql_close(conn);
  
  cout << "Hello, world!" << endl;
  return 0;
}
