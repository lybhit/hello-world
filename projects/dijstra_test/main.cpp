#include <iostream>
#include <eigen3/Eigen/Dense>
#include <math.h>

using namespace std;

#define MAXINT 1e3

float dis_point(Eigen::Vector2f from, Eigen::Vector2f to)
{
  return sqrt(pow(to.y() - from.y(), 2) + pow(to.x() - from.x(), 2));
}

void dijstra_ros(float id_arr[][7], int id_size, int source, int* prev, float* dist)
{
  bool  S[id_size];
  
  int n = id_size;
  
  for(int i = 0; i < id_size; ++i)
  {
    dist[i] = id_arr[source][i];
    
    S[i] = false;
   
    if(dist[i] == MAXINT)
      prev[i] = -1;
    else
      prev[i] = source;
  }
  
  dist[source] = 0;
  S[source] = true;
  prev[source] = -1;
  
  for(int i = 0; i < n; ++i)
  {
    int min_dist = MAXINT;
    int u = source;
    
    for(int j = 0; j < n; ++j)
    {
      if(!S[j] && dist[j] < min_dist)
      {
	u = j;
	min_dist = dist[j];
      }
    }
    
    S[u] = true;
    
    for(int j = 0; j < n; ++j)
    {
      if(!S[j] && id_arr[u][j] < MAXINT)
      {
	if(dist[u] + id_arr[u][j] < dist[j])
	{
	  dist[j] = dist[u] + id_arr[u][j];
	  prev[j] = u;
	}
      }
    }
  }
}

void print_seq(int* prev, int target)
{
  int temp = target;
  
  do{
    cout << prev[temp] << endl;
    temp = prev[temp];
  }while(prev[temp] != -1);
 
//   for(int i = 0; i < 7; ++i)
//   {
//     cout << prev[i] << endl;
//   }
  
}
 

int main(int argc, char **argv) {
  
  float id_arr[7][7];
  float dist[7];
  
  for(int i = 0; i < 7; ++i)
  {
    for(int j = 0; j < 7; ++j)
    {
      if(i != j)
      {
	id_arr[i][j] = MAXINT;
      }else{
	id_arr[i][j] = 0;
      }
    }
  }
  id_arr[0][1] = id_arr[1][0] = 1;
  id_arr[1][2] = id_arr[2][1] = 2;
  id_arr[1][6] = id_arr[6][1] = 1;
  id_arr[2][3] = id_arr[3][2] = 4;
  id_arr[3][4] = id_arr[4][3] = 1;
  id_arr[4][5] = id_arr[5][4] = 1;
  id_arr[4][6] = id_arr[6][4] = 1;
 
  int prev[7];
  dijstra_ros(id_arr, 7, 3, prev, dist);
  print_seq(prev, 0);
  
  cout << endl;
  
  for(int i = 0; i < 7; ++i)
  {
    cout << dist[i] << endl;
  }
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
