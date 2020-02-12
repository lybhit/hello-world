#include <iostream>
#include <vector>

using namespace std;

int main()
{
   vector<int> a;
   a.push_back(1);
   a.push_back(1);
   a.push_back(1);
   a.push_back(1);
   a.push_back(1);
   a.push_back(1);
   a.push_back(1);
   a.push_back(1);

   cout << " a size =" << a.size() << endl;

   a.clear();
   cout << "after clear, a size = " << a.size() << endl;
  
   
   a.push_back(1);
   a.push_back(1);
   a.push_back(1);
   a.push_back(1);
   a.push_back(1);
   
   cout << "after push_back, a size = " << a.size() << endl;
}
