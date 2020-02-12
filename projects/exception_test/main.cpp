#include <iostream>
#include <boost/exception/all.hpp>

using namespace boost;
struct my_err{};
int main(int argc, char **argv) {
  try
  {
    //使用enable_error_info包装自定义异常
    throw enable_error_info(my_err())
        << errinfo_errno(101)
        << errinfo_api_function("fopen");
  }
  catch(boost::exception& e)
  {
    std::cout <<diagnostic_information(e) << std::endl;
  }
  
  try{
    BOOST_THROW_EXCEPTION(std::logic_error("logic"));
  }
  catch(boost::exception& e)
  {
    std::cout << diagnostic_information(e) << std::endl;
  }
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
