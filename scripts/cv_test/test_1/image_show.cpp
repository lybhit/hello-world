#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

int main(int argc, char** argv)
{
  cv::namedWindow(argv[1], 1);

  cv::Mat img = cv::imread(argv[1]);

  cv::imshow(argv[1], img);

  while(true)
  {
    if(cv::waitKey(100) == 27) break;
  }

  cv::destroyWindow(argv[1]);

  exit(0);
}
