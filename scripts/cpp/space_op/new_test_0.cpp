#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main()
{
  steady_clock::time_point start = steady_clock::now();
  int **array = new int*[10];
  for(int i = 0; i < 10; ++i)
  {
    array[i] = new int[100000];
  }

  for(int i = 0; i < 10; ++i)
  {
    for(int j = 0; j < 100000; j ++)
    {
      array[i][j] = 100;
      cout << array[i][j] << ' ';
    }
  } 
  
  steady_clock::time_point end = steady_clock::now();
  duration<double> sec = duration_cast<duration<double>>(end - start);
  
  sleep(20);
  cout << sec.count() << "s\n";
  for(int i=0; i < 10; i++)
  {
    delete[] array[i];
  }
  delete[] array;
}
