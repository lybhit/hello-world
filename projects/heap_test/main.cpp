#include <iostream>
#include <vector>
#include <algorithm>

#include <limits>

#define POT_HIGH 1e10;

using namespace std;

template <class T>
struct greater1 {
    bool operator()(const T& a, const T& b) const {
      return a > b;
    }
};

template <class Iterator>
void print_ivec(Iterator begin, Iterator end)
{
    for(;begin != end; ++begin)
        cout << *begin << '\t';
    cout << endl;
}

int main(int argc, char **argv) {
  vector<int> a = {1, 12, 15, 20, 30};
  make_heap(a.begin(), a.end(), greater1<int>()); 
  print_ivec(a.begin(), a.end());
  
  a.pop_back();
  print_ivec(a.begin(), a.end());
  
  cout << "numeric_limits<float>::min() = " << numeric_limits<float>::min() << endl;
  
  return 0;
}
