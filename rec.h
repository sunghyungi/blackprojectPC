#ifndef REC_H
#define REC_H
#include "opencv2/opencv.hpp"
#include "mainwindow.h"
using namespace std;
using namespace cv;



class Rec{
public:
    VideoWriter writer;
public:
    void recvideo();
};
#endif // REC_H
