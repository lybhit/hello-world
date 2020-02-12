#include <iostream>
#include <boost/typeof/typeof.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace std;
using namespace boost::property_tree;
int main(int argc, char **argv) {
  ptree pt;
  read_xml("../conf.xml", pt);
  
  cout << pt.get<string>("conf.theme") << endl;
  cout << pt.get<int>("conf.clock_stytle") << endl;
  cout << pt.get<long>("conf.gui") << endl;
  cout << pt.get("conf.no_prop", 100) << endl;
  
  BOOST_AUTO(child, pt.get_child("conf.urls"));
  for(BOOST_AUTO(pos, child.begin()); pos != child.end();++pos)
  {
    cout << pos->second.data() << ".";
  }
  cout << endl;
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
