#include <iostream>
#include <string>
#include <boost/typeof/typeof.hpp>
#include <boost/bimap.hpp>

#include <boost/bimap/unordered_multiset_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/set_of.hpp>
#include <boost/bimap/vector_of.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/assign/list_inserter.hpp>

#include <boost/assign.hpp>
#include <boost/bimap.hpp>
using namespace boost;
using namespace boost::bimaps;
using namespace std;

//7.4.4复合类型的用法
template<typename T>
void print_map(T &m)
{
  for(BOOST_AUTO(pos, m.begin()); pos != m.end(); ++pos)
  {
    cout << pos->first << "<-->" << pos->second << endl;
  }
}

//7.4.5 使用标签
template<class Type, class Tag>
struct tagged{
  typedef Type value_type;
  typedef Tag tag;
};


int main(int argc, char **argv) {
  bimap<int, string> bm;
  
  //使用左视图
  bm.left.insert(make_pair(1, "111"));
  bm.left.insert(make_pair(2, "222"));
  
  //使用右视图
  bm.right.insert(make_pair("string", 10));
  bm.right.insert(make_pair("bimap", 20));
  
  //对左视图使用迭代器迭代
  for(BOOST_AUTO(pos, bm.left.begin()); 
    pos != bm.left.end(); ++pos)
  {
    cout << "left[" << pos->first << "]="
        << pos->second << endl;
  }
  
  //7.4.4
  bimap<unordered_multiset_of<int>,unordered_multiset_of<string>> bm_mul;
  bm_mul.left.insert(make_pair(1, "111"));
  bm_mul.left.insert(make_pair(2, "222"));
  bm_mul.left.insert(make_pair(2, "555"));
  
  bm_mul.right.insert(make_pair("string", 10));
  bm_mul.right.insert(make_pair("bimap", 20));
  bm_mul.right.insert(make_pair("bimap", 2));
  
  print_map(bm_mul.left);
  
  //声明右值的集合类型是序列或者随机访问类型的bimap
  bimap<set_of<int>, vector_of<string>> bm_1;
  bm_1.left.insert(make_pair(1, "111"));
  bm_1.left[2] = "222";
  bm_1.left[300] = "bimap";
  
  print_map(bm_1.left);
  
  //7.4.6
  typedef bimap<multiset_of<int>, vector_of<string>> bm_t;
  bm_t bm_2 = assign::list_of<bm_t::relation>(1, "111")(2, "222");
  assign::insert(bm_2.left)(3, "333") (4, "444");
//   push_back(bm.right)("555", 5)("666", 6);
  
  cout << bm_2.size() << endl;
  print_map(bm_2.left);
  
  //7.4.7 查找与替换
  typedef bimap<int, string> bm_t_1;
  bm_t_1 bm_3 = assign::list_of<bm_t_1::relation>(1, "mario")(2, "peach");
  
  BOOST_AUTO(pos, bm_3.left.find(1));
  cout << "[" << pos->first << "]" << pos->second << endl;
  
  BOOST_AUTO(pos2, bm_3.right.find("peach"));
  cout << "[" << pos2->first << "]" << pos2->second << endl;
  
  BOOST_AUTO(pos3, bm_3.left.find(1));
  bm_3.left.replace_key(pos3, 111);
  bm_3.left.replace_data(pos3, "liuqi");
  cout << "[" << pos3->first << "]" << pos3->second << endl;
  
  //7.4.9 高级议题
  typedef bimap<int, string> bm_t_2;
  bm_t_2 bm_4;
  bm_4.left.insert(bm_t_2::left_value_type(1, "one"));
  bm_4.right.insert(bm_t_2::right_value_type("two", 222));
  print_map(bm_4.left);
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
