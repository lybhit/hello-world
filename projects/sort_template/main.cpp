#include <iostream>
#include <vector>
#include <boost/timer.hpp>
#include <boost/random.hpp>
#include <boost/random/random_number_generator.hpp>
#include <boost/generator_iterator.hpp>

using namespace std;

// quick bubble sort
void bubble_sort(vector<int>& input)
{
  unsigned int i = 0;
  int swap;
  while(i < input.size()-1)
  {
    if(input[i] > input[i+1])
    {
      swap = input[i];
      input[i] = input[i+1];
      input[i+1] = swap;
      
      if(i > 0)
        --i;
    }
    else
      ++i;
  }
}

void play(int a)
{
  cout << a << endl;
}

int main(int argc, char **argv) {
  boost::random::mt19937 rng(time(0));
  
  vector<int> num;
  for(int i = 0; i < 100; ++i)
  {
    num.push_back(rng()%100);
//     cout << rng()%100 << endl;
  }
  
  bubble_sort(num);
  
  for_each(num.begin(), num.end(), play);
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
