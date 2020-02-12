#include <iostream>
#include "boost/lambda/lambda.hpp"
#include "boost/lambda/casts.hpp"
#include "boost/lambda/if.hpp"
#include "boost/lambda/bind.hpp"

using namespace std;

class base{
public:
	virtual ~base() {}
	void do_stuff() const {
		cout << "void base::do_stuff() const \n";
	}

};

class derived : public base {
public:
	void do_more_stuff() const {
		cout << "void derived::do_more_stuff () const\n";
	}
};

int main() {
	using namespace boost::lambda;
	base* p1 = new base;
	base* p2 = new derived;
	derived* pd = 0;
	(if_(var(pd) = ll_dynamic_cast<derived*>(_1))
		[bind(&derived::do_more_stuff, var(pd))].
		else_[bind(&base::do_stuff, *_1)])(p1);
	(if_(var(pd) = ll_dynamic_cast<derived*>(_1))
		[bind(&derived::do_more_stuff, var(pd))].
		else_[bind(&base::do_stuff, *_1)])(p2);

}