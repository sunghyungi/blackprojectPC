#ifndef LINESEARCH_H
#define LINESEARCH_H
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;



class Linesearch
{
public:
    void draw_houghLines(Mat image, Mat& dst, vector<Vec2f> lines, int nline);
    Mat Line_edge(Mat frame1);
};

#endif // LINESEARCH_H
