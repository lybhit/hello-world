#include <iostream>
#include <hash_map>
#include <boost/unordered_map.hpp>
#include <string>
#include <boost/assign.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/typeof/typeof.hpp>

//7.3.5 性能比较
#include <typeinfo>
#include <set>
#include <hash_set>
#include <boost/unordered_set.hpp>
#include <boost/random.hpp>
using namespace boost;
using namespace std;

//7.3.5
template<typename T>
void fill_set(T &c)
{
  variate_generator<mt19937, uniform_int<> > gen(mt19937(), uniform_int<>(0,100));
  for(int i = 0; i < 10000; ++i)
    c.insert(gen());
}

// template<typename T>
// void test_perform()
// {
//   T c;
//   cout << typeid(c).name() << endl;
//   {
//     ptimer t;//ptimer 详细见2.7.10实现
//     fill_set(c);
//   }
//   {
//     ptimer t;
//     c.cout(10);
//   }
//   {
//     ptimer t;
//     c.find(20);
//   }
// }




int main(int argc, char **argv) {
  unordered_map<int, string> um = assign::map_list_of(1,"one") (2,"two") (3,"three");
  um.insert(make_pair(10, "ten"));
  cout << um[10] << endl;
  um[11] = "eleven";
  um[15] = "fifteen";
  
  BOOST_AUTO(p, um.begin());
  for(p; p != um.end(); ++p)
  {
    cout << p->first << "-" << p->second << ",";
  }
  cout << endl;
  
  um.erase(11);
  cout << um.size() << endl;
  __gnu_cxx::hash_map<int, string> hm = assign::map_list_of(4, "four") (5,"five") (6, "six");
  BOOST_AUTO(q, hm.begin());
  for(q; q != hm.end(); ++q)
  {
    cout << q->first << "-" << q->second << ",";
  }
  cout << endl;
  
  //7.3.6
  unordered_set<int> us = (assign::list_of(1), 2, 3, 4);
  cout << us.bucket_count() << endl;
  for(int i = 0; i < us.bucket_count(); ++i)
  {
    cout << us.bucket_size(i) << ",";
  }
  
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
