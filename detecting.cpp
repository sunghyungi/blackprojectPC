#include "mainwindow.h"
#include "detecting.h"
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat Detecting::detect(Mat frame1){


    CascadeClassifier classifier("../~detectxml/cascade2.xml");

    vector<Rect> car;
    classifier.detectMultiScale(frame1, car);

    for (Rect rc: car){
        rectangle(frame1, rc, Scalar(255, 0, 255),2);
    }



    return frame1;
}


Mat Detecting::detect2(Mat frame1){


    CascadeClassifier classifier2("../~detectxml/upperbody.xml");

    vector<Rect> body;
    classifier2.detectMultiScale(frame1, body);

    for (Rect rc: body){
        rectangle(frame1, rc, Scalar(255, 0, 0),2);
    }


    return frame1;
}
