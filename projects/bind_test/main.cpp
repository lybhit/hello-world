#include <iostream>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <algorithm>
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>


using namespace std;
using namespace boost;

int f(int a, int b)
{
    return a + b;
}

int g(int a, int b, int c)
{
    return a + b + c;
}

struct F
{
  int operator()(int a, int b) {return a-b;}
  bool operator()(long a, long b) {return a == b;}
};

struct F2
{
    int s;

    typedef void result_type;
    void operator()( int x ) { s += x; }
};

struct X
{
    bool f(int a){
      return a < 10;
    }
};


int main(int argc, char **argv) {
  
  int a = boost::bind(f,1,2)();
  //int a = 3;
  cout << a << endl;
  
  int b = boost::bind(f,5,_1)(a);
  cout << b << endl;
  
  F f;
  int x = 104;
  int c = boost::bind<int>(f, _1, _1)(x);
  cout << c << endl;
  
  x = 8;
  bool d = boost::bind(std::less<int>(), _1, 9)(x);
  cout << d << endl;
  
  F2 f2 = {0};
  int e[] = {1, 2, 3};
  for_each(e, e+3, boost::bind(boost::ref(f2), _1));
  cout << f2.s << endl;
  
  X xx;
  boost::shared_ptr<X> p(new X);
  
  int i = 5;
  bool a1 = boost::bind(&X::f, boost::ref(xx), _1)(i); //x.f(i)
  bool a2 = bind(&X::f, &xx, _1)(i); //(&x)->f(i)
  bool a3 = bind(&X::f, xx, _1)(i); //(internal copy of x).f(i)
  bool a4 = bind(&X::f, p, _1)(i);//(internal copy of p)->f(i)
  cout << a1 << endl;
  cout << a2 << endl;
  cout << a3 << endl;
  cout << a4 << endl;
  return 0;
}
