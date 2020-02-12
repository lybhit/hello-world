#include <iostream>
#include <string>
#include <boost/dynamic_bitset.hpp>
#include <boost/utility/binary.hpp>
using namespace boost;
using namespace std;

int main(int argc, char **argv) {
  dynamic_bitset<> db1;
  dynamic_bitset<> db2(10);
  dynamic_bitset<> db3(0x16, BOOST_BINARY(10101));
  dynamic_bitset<> db4(string("0100"));
  dynamic_bitset<> db5(db3);
  
  dynamic_bitset<> db6;
  db6 = db4;
  
  cout << hex << db5.to_ulong() << endl;
  cout << db4[0] << db4[1] << db4[2] << endl;
  
  //7.2.6 类型转换
  dynamic_bitset<> db(10, BOOST_BINARY(1010101));
  cout << db << endl;
  cout << db.to_ulong() << endl;
  
  db.append(10);
  cout << db << endl;
  cout << db.to_ulong() << endl;
  db.push_back(1);
//   cout << db.to_ulong() << endl;//over_flow
  
  string str;
  to_string(db,str);
  cout << str << endl;
  
  //7.2.7 集合操作
  dynamic_bitset<> db_7_1(5, BOOST_BINARY(10101));
  dynamic_bitset<> db_7_2(5, BOOST_BINARY(10010));
  
  cout << (db_7_1 | db_7_2) << endl;
  cout << (db_7_1 & db_7_2) << endl;
  cout << (db_7_1 - db_7_2) << endl;
  dynamic_bitset<> db_7_3(5, BOOST_BINARY(101));
  assert(db_7_3.is_proper_subset_of(db_7_1));
  
  dynamic_bitset<> db_7_4(db_7_2);
  assert(db_7_4.is_subset_of(db_7_2));
  assert(!db_7_4.is_proper_subset_of(db_7_2));
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
