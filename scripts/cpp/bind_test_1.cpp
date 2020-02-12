#include <iostream>
#include "boost/bind.hpp"
#include <string>
using namespace std;
class tracer{
public:
  tracer(){
    cout << "tracer::tracer()\n";
  }

  tracer(const tracer& other){
    cout << "tracer::tracer(const tracer& other)\n";
  }

  tracer& operator=(const tracer& other)
  {
    cout << "tracer& operator=(const tracer& other)\n";
  }

  ~tracer(){
    cout << "tracer::~tracer()\n";
  }
  
  void print(const std::string& s) const {
    std::cout << s << '\n';
  }
};

int main()
{
  tracer t;
  boost::bind(&tracer::print, boost::ref(t), _1)
    (string("I am called on a copy of t\n"));
  return 0;
}
