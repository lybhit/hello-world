#include<iostream>
#include <string>
#include <vector>
#include <fstream>  //文件流库函数
 
using namespace std;
 
int cost[10][10];
 
int main()
{  
    int v, w, weight;
    ifstream infile;   //输入流
    ofstream outfile;   //输出流
 
    infile.open("./data.txt", ios::in); 
    if(!infile.is_open ())
        cout << "Open file failure" << endl;
    while (!infile.eof())            // 若未到文件结束一直循环
    {
        infile >> v >> w >> weight;
        cost[v][w] = weight;
        cost[w][v] = weight;                
    }
    infile.close();   //关闭文件
     
    outfile.open("./result.txt", ios::app);   //每次写都定位的文件结尾，不会丢失原来的内容，用out则会丢失原来的内容
    if(!outfile.is_open ())
        cout << "Open file failure" << endl;
    for (int i = 0; i != 10; ++i)
    {
        for (int j = 0; j != 10; ++j)
        {
            outfile << i << "\t" << j << "\t" << cost[i][j] << endl;  //在result.txt中写入结果
        }
 
    }
    outfile.close();
 
    return 0;
//    while (1);
}
