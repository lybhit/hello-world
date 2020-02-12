#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>

#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Dense>

using namespace std;
using namespace cv;

// #define MAP_WIDTH_  1694
// #define MAP_HEIGHT_ 1727
// #define WIDTH_OFFSET_  784
// #define HEIGHT_OFFSET_ 895

// #define MAP_WIDTH_  1698
// #define MAP_HEIGHT_ 1620
// #define WIDTH_OFFSET_  783
// #define HEIGHT_OFFSET_ 631

// #define MAP_WIDTH_  1698
// #define MAP_HEIGHT_ 1620
// #define WIDTH_OFFSET_  1017
// #define HEIGHT_OFFSET_ 507

// #define MAP_WIDTH_  1698
// #define MAP_HEIGHT_ 1620
// #define WIDTH_OFFSET_  529
// #define HEIGHT_OFFSET_ 608

// #define MAP_WIDTH_  1698
// #define MAP_HEIGHT_ 1620
// #define WIDTH_OFFSET_  520
// #define HEIGHT_OFFSET_ 606

// #define MAP_WIDTH_  1698
// #define MAP_HEIGHT_ 1620
// #define WIDTH_OFFSET_  420
// #define HEIGHT_OFFSET_ 1010

#define MAP_WIDTH_  1698
#define MAP_HEIGHT_ 1620
#define WIDTH_OFFSET_  499
#define HEIGHT_OFFSET_ 988
class color_para
{
public:
  color_para():red_para(255),green_para(0),blue_para(0){}  
  color_para(uint8_t a, uint8_t b, uint8_t c):red_para(a),green_para(b),blue_para(c){}
  
  uint8_t GetRedPara()
  {
    return this->red_para;
  } 
  uint8_t GetGreenPara()
  {
    return this->green_para;
  }  
  uint8_t GetBluePara()
  {
    return this->blue_para;
  }
  
private:
  uint8_t red_para;
  uint8_t green_para;
  uint8_t blue_para; 
};

void load_scan_from_file(vector<vector<Eigen::Vector2d>>& val_set, const string& str)
{
  cout << "load file data" << endl;
  cout << str << endl;
  std::ifstream infile;   //输入流
  const char* p = str.c_str();
  infile.open(p, std::ios::in); 
  if(!infile.is_open ())
  {
    return;
  }
  vector<int> vec_data;
  int counter = 0;  
  int v;
  while (!infile.eof())            // 若未到文件结束一直循环
  {
      infile >> v;
      vec_data.push_back(v); 
      counter++;              
  }
  infile.close();   //关闭文件

  cout << "from input data size = " << counter << endl; 
  vector<Eigen::Vector2d> temp_set;

  for (unsigned int i = 0; i < counter; i++)
  {
    // calculate position in laser frame
    int r = vec_data[i];
    int y = r / MAP_WIDTH_;
    int x = r - y * MAP_WIDTH_;
    Eigen::Vector2d val(x, y);
    temp_set.push_back(val);
  }
  val_set.push_back(temp_set);
}

void load_map_from_file(vector<vector<Eigen::Vector2d>>& val_set, const string& str)
{
  cout << "load file data" << endl;
  cout << str << endl;
  std::ifstream infile;   //输入流
  const char* p = str.c_str();
  infile.open(p, std::ios::in); 
  if(!infile.is_open ())
  {
    // ROS_INFO("Open file failure" );
    return;
  }
  vector<int> vec_data;
  int counter = 0;  
  int v;
  while (!infile.eof())            // 若未到文件结束一直循环
  {
      infile >> v;
      vec_data.push_back(v); 
      counter++;              
  }
  infile.close();   //关闭文件

  cout << "from input data size = " << counter << endl; 
  vector<Eigen::Vector2d> temp_set;

  for (unsigned int i = 0; i < counter; i++)
  {
    // calculate position in laser frame
    int r = vec_data[i];
    int y = r / MAP_WIDTH_;
    int x = r - y * MAP_WIDTH_;
//     int y_0 = r / MAP_WIDTH_;
//     int x = r - y_0 * MAP_WIDTH_;
//     int y = MAP_HEIGHT_ - y_0;
    Eigen::Vector2d val(x, y);
    temp_set.push_back(val);
  }
  val_set.push_back(temp_set);
}

void image_show(const vector<vector<Eigen::Vector2d>>& val_set)
{
  int width = MAP_WIDTH_;
  int height = MAP_HEIGHT_;

  cout << "width: " << width << endl;
  cout << "height: " << height << endl;
  
  std::map<string, color_para> color_map;
  color_map.insert(std::pair<string, color_para>("1Red",color_para(255,0,0)));
  color_map.insert(std::pair<string, color_para>("2Green",color_para(0,255,0)));
  color_map.insert(std::pair<string, color_para>("3ZBlue",color_para(0,0,255)));
  color_map.insert(std::pair<string, color_para>("4Maroon",color_para(176,48,96)));
  color_map.insert(std::pair<string, color_para>("5Snow4",color_para(139,137,137)));
  color_map.insert(std::pair<string, color_para>("6Orange1",color_para(255,165,0)));
  color_map.insert(std::pair<string, color_para>("7ZOrange4",color_para(139,90,0)));
  color_map.insert(std::pair<string, color_para>("8Yellow1",color_para(255,255,0)));
  color_map.insert(std::pair<string, color_para>("9aleGreen4",color_para(84,139,84)));
  color_map.insert(std::pair<string, color_para>("DeepPink1",color_para(255,20,147)));
  color_map.insert(std::pair<string, color_para>("Chocolate4",color_para(139,69,19)));

  vector<vector<Point2d>> ptSet;

  vector<Point2d> temp_ptSet;
  for(int i = 0; i < val_set.size()-1; ++i)
  {
    for(int j = 0; j < val_set[i].size(); ++j)
    {
      int x = val_set[i].at(j).x() + WIDTH_OFFSET_;
      int y = val_set[i].at(j).y() + HEIGHT_OFFSET_;

      Point2d pt(x, y);
      temp_ptSet.push_back(pt);
    }
    ptSet.push_back(temp_ptSet);
  }
  

    for(int j = 0; j < val_set.back().size(); ++j)
    {
      int x = val_set.back().at(j).x();
      int y = val_set.back().at(j).y();

      Point2d pt(x, y);
      temp_ptSet.push_back(pt);
    }
    ptSet.push_back(temp_ptSet);

   //绘制点集中所有点
  vector<Mat> img_set;
  Mat img(height, width, CV_8UC3, Scalar(255, 255, 255));
  for (unsigned int i = 0; i < ptSet.size(); i++)
  {
    img_set.push_back(img);
  }
  
  std::map<string, color_para>::iterator it = color_map.begin();

  for (unsigned int i = 0; i < ptSet.size(); i++, it++)
  {  
    for(int j = 0; j < ptSet[i].size(); ++j)
    {
      circle(img_set[i], ptSet[i].at(j), 2, Scalar(it->second.GetRedPara(), it->second.GetGreenPara(), it->second.GetBluePara()), 1, 8);  
    } 
    cout << static_cast<int>(it->second.GetRedPara()) << ' ' << static_cast<int>(it->second.GetGreenPara()) << ' ' << static_cast<int>(it->second.GetBluePara()) << endl;
    
    namedWindow(it->first,0);  
    imshow(it->first, img_set[i]);
    waitKey();
    
    string input;
    cout << "go ahead? print yes/no" << endl;
    cin >> input;
    if(input == "yes")
    {
      continue;
    }else{
      break;
    }
  }
  
//  Mat dst2;
//  pyrDown(img, dst2, Size(img.cols * 0.5, img.rows * 0.5));

//  namedWindow("filtering",0);
  
//  imshow("filtering", img);
  waitKey();
}

int main(int argc, char** argv)
{
  vector<vector<Eigen::Vector2d>> val_set;
  vector<stringstream> str(10);
  
  for(int i = 0; i < 10; ++i)
  {
    string temp_str;
    str[i] << "/home/suirui/data" << i << ".txt";
    str[i] >> temp_str;
    cout << temp_str << endl;
    load_scan_from_file(val_set, temp_str);
  }
  load_map_from_file(val_set, "/home/suirui/map_index.txt");
  cout << "val_set.size() = " << val_set.size() << endl;
  image_show(val_set);
  return 0;
}
