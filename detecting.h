#ifndef DETECTING_H
#define DETECTING_H
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;



class Detecting
{
public:
    Mat detect(Mat frame1);
    Mat detect2(Mat frame1);

};
#endif // DETECTING_H
