#include "mainwindow.h"
#include "linesearch.h"
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;



// 엣지 검출, 라인 그리기
void Linesearch::draw_houghLines(Mat image, Mat& dst, vector<Vec2f> lines, int nline)
{
    if (image.channels() == 3) image.copyTo(dst);
    else cvtColor(image, dst, COLOR_GRAY2RGB);

    for (int i = 0; i < min((int)lines.size(), nline); i++)
    {
        float rho = lines[i][0], theta = lines[i][1];
        double a = cos(theta), b = sin(theta);

        Point2d delta(1000 * -b, 1000 * a);
        Point2d pt(a*rho, b*rho);
        line(dst, pt + delta, pt - delta, Scalar(0, 255, 0), 1, LINE_AA);
    }
}




Mat Linesearch::Line_edge(Mat frame1)
{
                Mat lineframe;
                cvtColor(frame1, lineframe, COLOR_BGR2GRAY);
                double rho = 1, theta = CV_PI/180;
                Mat canny, dst1;
                GaussianBlur(lineframe, canny, Size(5,5), 2, 2);
                Canny(canny, canny, 100 ,150, 3);
                vector<Vec2f> lines1;
                HoughLines(canny, lines1, rho, theta, 50);
                draw_houghLines(canny, dst1, lines1, 10);

                return dst1;

}
