#include <iostream>
#include <vector>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/core/ref.hpp>
#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost;

int f(int a, int b)
{
  return a+b;
}

struct demo_class
{
  int add(int a, int b)
  {
    return a+b;
  }
  int operator()(int x) const
  {
    return x*x;
  }
};

template<typename T>
struct summary
{
  typedef void result_type;
  T sum;
  summary(T v = T()):sum(v){}
  void operator()(T const &x)
  { sum += x; }
};

//11.4.7 用于回调
class demo_class_1
{
private:
  typedef boost::function<void(int)> func_t;
  func_t func;
  
  int n;
public:
  demo_class_1(int i): n(i){}
  
  template<typename CallBack>
  void accept(CallBack f)
  {
    func = f;
  }
  
  void run()
  {
    func(n);
  }
};

void call_back_func(int i)
{
  cout << "call_back_func:";
  cout << i * 2 << endl;
}

class call_back_obj
{
private:
  int x;
public:
  call_back_obj(int i): x(i){}
  void operator()(int i)
  {
    cout << "call_back_obj:";
    cout << i * x++ << endl;
  }
};

class call_back_factory
{
public:
  void call_back_func1(int i)
  {
    cout << "call_back_factory1:";
    cout << i * 2 << endl;
  }
  
  void call_back_func2(int i, int j)
  {
    cout << "call_back_factory1:";
    cout << i * j * 2 << endl;
  }
};

int main(int argc, char **argv) {
  boost::function<int(int, int)> func;    //无参构造一个function对象
  assert(!func);                          //此时，function不持有任何对象
  
  func = f;                               //func存储了函数f
  if(func)                                //function可以转换为bool值
  {
    cout << func(10, 10) << endl;         //调用function的 operator()
  }
  
  func = 0;                               //function清空，相当于clear()
  assert(func.empty());
  
  boost::function<int(demo_class&, int, int)> func1;
  func1 = boost::bind(&demo_class::add, _1, _2, _3);
  demo_class sc;
  cout << func1(sc, 10, 20) << endl;
  
  boost::function<int(int, int)> func2;
  func2 = bind(&demo_class::add, &sc, _1, _2);
  cout << func2(10, 20) << endl;
  
  //11.4.6 使用ref库
  boost::function<int(int)> func3;
  func3 = boost::cref(sc);                //使用cref()函数包装常对象的引用
  cout << func3(10) << endl;              //调用被引用的对象
  
  vector<int> v = (assign::list_of(1), 3, 5, 7, 9);
  summary<int> s;
  boost::function<void(int const &)> func4(boost::ref(s));
  std::for_each(v.begin(), v.end(), func4);
  cout << s.sum << endl;
  
  //11.4.7 用于回调
  demo_class_1 dc_1(1000);
  dc_1.accept(call_back_func);
  dc_1.run();
  
  demo_class_1 dc_2(10);
  call_back_obj cbo(2);
  dc_2.accept(boost::ref(cbo));
  dc_2.run();
  dc_2.run();
  
  demo_class_1 dc_3(10);
  call_back_factory cbf;
  dc_3.accept(bind(&call_back_factory::call_back_func1, &cbf, _1));
  dc_3.run();
  
  dc_3.accept(bind(&call_back_factory::call_back_func2, &cbf, _1, 5));
  dc_3.run();
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
