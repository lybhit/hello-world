#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <boost/assign.hpp>
#include <cstdlib>
using namespace boost::assign;

int main(int argc, char **argv) {
  //4.4.4
  std::vector<int> v = list_of(1).repeat(3,2) (3) (4) (5);
  for(auto it = v.begin(); it != v.end(); ++it)
  {
    std::cout << *it << ' ';
  }
  
  std::multiset<int> ms;
  insert(ms).repeat_fun(5, &rand).repeat(2,1), 10;
  
  std::deque<int> d;
  push_front(d).range(v.begin(), v.begin() + 5);
  
  //4.4.5
  std::stack<int> stk = (list_of(1), 2, 3).to_adapter();
  while(!stk.empty())
  {
    std::cout << stk.top() << " ";
    stk.pop();
  }
  std::cout << std::endl;
  
  std::queue<std::string> q = (list_of("china") ("us") ("uk")).repeat(2, "russia").to_adapter();
  while(!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
  
  std::priority_queue<double> pq = (list_of(1.414), 1.732, 2.236).to_adapter();
  while(!pq.empty())
  {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
