#include "mainwindow.h"
#include "colorchange.h"
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


Mat Colorchange::colorch(Mat frame1, int channel, bool redbool, bool greenbool, bool bluebool){

    Mat bgr[3];
    split(frame1,bgr);
    Mat frame2, ch_012;
    Mat zeros(bgr[0].size(),CV_8UC1,int(0));



    if(channel == 3){
        if(!redbool){
            bgr[0] = zeros;
        }
        if(!greenbool){
            bgr[1] = zeros;
        }
        if(!bluebool){
            bgr[2] = zeros;
        }

        vector<Mat> vec_012;
        vec_012.push_back(bgr[0]);
        vec_012.push_back(bgr[1]);
        vec_012.push_back(bgr[2]);
        merge(vec_012, ch_012);
        frame2 = ch_012;
    }
    else if(channel == 1){

        Mat chamat(bgr[0].size(),CV_8UC1, int(0));


        if(redbool && greenbool && bluebool){
            chamat = bgr[0]/3+bgr[1]/3+bgr[2]/3;
        }
        else if(redbool && greenbool){
            chamat = bgr[0]/2+bgr[1]/2;
        }
        else if(redbool && bluebool){
            chamat = bgr[0]/2+bgr[2]/2;
        }
        else if(greenbool && bluebool){
            chamat = bgr[1]/2+bgr[2]/2;
        }
        else if(redbool){
            chamat = bgr[0];
        }
        else if(greenbool){
            chamat = bgr[1];
        }
        else if(bluebool){
            chamat = bgr[2];
        }


        cvtColor(chamat, frame2, COLOR_GRAY2RGB);

    }

    return frame2;

}

