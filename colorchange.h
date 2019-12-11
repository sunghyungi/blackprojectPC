#ifndef COLORCHANGE_H
#define COLORCHANGE_H
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;



class Colorchange
{
public:
   Mat colorch(Mat frame1, int channel, bool redbool, bool greenbool, bool bluebool);

};
#endif // COLORCHANGE_H
