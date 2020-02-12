#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <algorithm>

using namespace std;

template <class Operation1, class Operation2>
class unary_compose : public unary_function<typename Operation2::argument_type,
                                            typename Operation1::result_type>{
protected:
  Operation1 op1;
  Operation2 op2;
public:
  unary_compose(const Operation1& x, const Operation2& y):op1(x), op2(y) {}
  typename Operation1::result_type operator()(const typename Operation2::argument_type& x) const {
    return op1(op2(x));
  }
};

template <class Operation1, class Operation2>
inline unary_compose<Operation1, Operation2> compose1(const Operation1& op1, const Operation2& op2) {
  return unary_compose<Operation1,Operation2>(op1, op2);
}

int main(int argc, char **argv) {
  ostream_iterator<int> coutie(cout, " ");
  int ia[6] = {2,21,12,7,19,23};
  vector<int> iv(ia, ia+6);
  for_each(iv.begin(), iv.end(), compose1(bind2nd(multiplies<int>(),3), bind2nd(plus<int>(),2)));
  
  copy(iv.begin(), iv.end(), coutie);
  cout << endl;
  
  transform(iv.begin(), iv.end(), coutie, compose1(
                                                   bind2nd(multiplies<int>(),3),
						   bind2nd(plus<int>(),2)));
  cout << endl;
  return 0;
}
