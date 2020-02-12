#include <iostream>
#include "observe.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <boost/typeof/typeof.hpp>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>

using namespace boost::signals2;
using namespace std;

void slots1()
{
  cout << "slot1 called" << endl;
}

void slots2()
{
  cout << "slot2 called" << endl;
}

template<int N>
struct slots
{
  void operator()()
  {
    cout << "slot" << N << " called" << endl;
  }
};

//11.5.4 信号的返回值
template<int N>
struct slots_1
{
  int operator()(int x)
  {
    cout << "slot_1 " << N << " called" << endl;
    return x * N;
  }
};

//11.5.5 合并器
template<typename T>
class combiner
{
  T v;
public:
  typedef std::pair<T, T> result_type;
  combiner(T t = T()):v(t){}
  
  template<typename InputIterator>
  result_type operator()(InputIterator begin, InputIterator end)
  {
    if(begin == end)
    {
      return result_type();
    }
    vector<T> vec(begin, end);
    T sum = std::accumulate(vec.begin(), vec.end(), v);
    T max = *std::max_element(vec.begin(), vec.end());
    return result_type(sum, max);
  }
};

//11.5.6 管理信号的连接
template<int N>
bool operator ==(const slots_1<N>&, const slots_1<N>&)
{
  return true;
}


int main(int argc, char **argv) {
  
  signal<void()> sig;
  
  sig.connect(&slots1);
  sig.connect(&slots2);
  

  sig.connect(slots<100>(),at_front);
  sig.connect(5,slots<51>(),at_back);
  sig.connect(5,slots<55>(),at_front);
  sig.connect(3,slots<30>(),at_front);
  sig.connect(3,slots<33>(),at_back);
  sig(); 
  
  //11.5.4 信号的返回值
  signal<int(int)> sig_1;
  sig_1.connect(slots_1<10>());  
  sig_1.connect(slots_1<20>());  
  sig_1.connect(slots_1<50>()); 
  
//   sig_1(2);
  cout << *sig_1(2) << endl;
  
  //11.5.5 合并器
  signal<int(int), combiner<int>> sig_2;
  sig_2.connect(slots_1<10>());
  sig_2.connect(slots_1<20>());
  sig_2.connect(slots_1<30>(), at_front);
  
  BOOST_AUTO(x, sig_2(2));
  cout << x.first << "," << x.second << endl;
  
  //11.5.6 管理信号的连接
  signal<int(int)> sig_3;
  assert(sig_3.empty());
  sig_3.connect(0,slots_1<10>());
  sig_3.connect(0,slots_1<20>());
  sig_3.connect(1,slots_1<30>());
  assert(sig_3.num_slots() == 3);
  sig_3.disconnect(0);
  assert(sig_3.num_slots() == 1);
  
  sig_3.disconnect(slots_1<30>());
  assert(sig_3.empty());
  
  //11.5.7 更灵活的管理信号连接
  signal<int(int)> sig_4;
  connection c1 = sig_4.connect(0, slots_1<10>());
  connection c2 = sig_4.connect(0, slots_1<20>());
  connection c3 = sig_4.connect(1, slots_1<30>());
  
  c1.disconnect();
  assert(sig_4.num_slots() == 2);
  assert(!c1.connected());
  assert(c2.connected());
  
  //11.5.9 应用于观察模式
  ring r;
  nurse<nurse1> n1;
  nurse<nurse2> n2;
  baby<baby1> b1;
  baby<baby2> b2;
  guest g;
  
  r.connect(boost::bind(&nurse<nurse1>::action, n1));
  r.connect(boost::bind(&nurse<nurse2>::action, n2));
  r.connect(boost::bind(&baby<baby1>::action, b1));
  r.connect(boost::bind(&baby<baby2>::action, b2));
  
  g.press(r);
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
