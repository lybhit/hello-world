#ifndef _OBSERVE_H_
#define _OBSERVE_H_

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <boost/typeof/typeof.hpp>
#include <boost/signals2.hpp>
#include <boost/random.hpp>

using namespace std;
using namespace boost;
using namespace boost::signals2;

class ring
{
public:
  typedef signal<void()> signal_t;
  typedef signal_t::slot_type slot_t;
  
  connection connect(const slot_t& s)
  {
    return alarm.connect(s);
  }
  void press()
  {
    cout << "Ring alarm..." << endl;
    alarm();
  }
private:
  signal_t alarm;
};

typedef random::variate_generator<rand48,uniform_smallint<>> bool_rand;
bool_rand g_rand(rand48(time(0)), uniform_smallint<>(0,100));

extern char const nurse1[] = "Mary";
extern char const nurse2[] = "Kate";

template<char const *name>
class nurse
{
private:
  bool_rand &rand;
public:
  nurse():rand(g_rand){}
  void action()
  {
    cout << name;
    if(rand() > 30)
    {
      cout << "wakeup and open door" << endl;
    }
    else
    {
      cout << " is sleeping..." << endl;
    }
  }
};

extern char const baby1[] = "Tom";
extern char const baby2[] = "Jerry";
template<char const *name>
class baby
{
private:
  bool_rand &rand;
public:
  baby():rand(g_rand){}
  void action()
  {
    cout << "Baby" << name;
    if(rand() > 50)
    {
      cout << "wakeup and crying loudly..." << endl;
    }
    else
    {
      cout << "is sleeping sweetly..." << endl;
    }
  }
};

class guest
{
public:
  void press(ring &r)
  {
    cout << "A guest press the ring." << endl;
    r.press();
  }
};





#endif




 
