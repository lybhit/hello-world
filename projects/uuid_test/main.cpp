#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <vector>
using namespace boost::uuids;
using namespace std;

//4.10.4
class uuid_t : public uuid{
private:
  static random_generator rgen;
  static string_generator sgen;
public:
  uuid_t(): uuid(rgen()){}
  uuid_t(int): uuid(nil_uuid()) {}
  uuid_t(const char* str): uuid(sgen(str)) {}
  uuid_t(const uuid& u, const char* str):
      uuid(name_generator(u)(str)) {}
  explicit uuid_t(const uuid& u): uuid(u) {}
  
  operator uuid(){return static_cast<uuid&>(*this);}
  operator uuid() const
  {return static_cast<const uuid&>(*this);}
};
random_generator uuid_t::rgen;
string_generator uuid_t::sgen;

int main(int argc, char **argv) {
  uuid u;
  assert(uuid::static_size() == 16);
  assert(u.size() == 16);
  
  std::vector<unsigned char> v(16, 7);
  std::copy(v.begin(), v.end(), u.begin());
  assert(u.data[0] == u.data[1] && u.data[15] == 7);
  
  std::cout << u << std::endl;
  std::fill_n(u.data+ 10, 6, 8);
  std::cout << u << std::endl;
  
  //4.10.4
  uuid_t u0 = 0;
  assert(u0.is_nil());
  
  uuid_t u1, u2;
  cout << u1 << endl;
  cout << u2 << endl;
  
  uuid_t u3("{01234567-89ab-cdef-0123-456789abcdef}");
  cout << u3 << endl;
  
  cout << uuid_t(u3, "test name gen") << endl;
  
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
