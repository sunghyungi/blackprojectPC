#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;



class Histogram
{
public:
    void calc_Histo(const Mat& image, Mat& hist, int bins, int range_max = 256);
    Mat  make_palatte(int rows, int num);
    void draw_histo_hue(Mat hist, Mat &hist_img, Size size = Size(256, 200), int a = 0);
    Mat histg(Mat frame, int num);
};

#endif // HISTOGRAM_H


