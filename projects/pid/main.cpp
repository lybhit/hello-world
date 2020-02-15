#include <iostream>
#include <unistd.h>
#include <chrono>
#include <ctime>
#include <ratio>
#include "pid.h"

int main(int argc, char **argv) {
  using namespace std::chrono;
  
  steady_clock::time_point t1 = steady_clock::now();
  steady_clock::time_point t2 = steady_clock::now();
 
  
  PID_t theta_pid, angular_pid;
  
  pid_init(&theta_pid, 0.02);
  //pid_init(&angular_pid, 0.02);
  
  pid_set_parameters(&theta_pid, 1, 5, 0, 600, 88);
  
  duration<double> time_span;
  float input = 0;
  std::cout << "output:" << std::endl;
  do{
    input += pid_calculate(&theta_pid, 600, input, 1, 0.02);
    usleep(20000);
    std::cout << input << ' ';  
    t2 = steady_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
  }while(time_span.count() <= 3);
  
  std::cout << std::endl;
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
