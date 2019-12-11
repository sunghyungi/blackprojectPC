#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(new QGraphicsScene(this));
    ui->graphicsView->scene()->addItem(&pixmap);

    ui->redHisto->setScene(new QGraphicsScene(this));
    ui->redHisto->scene()->addItem(&pixmap2);

    ui->greenHisto->setScene(new QGraphicsScene(this));
    ui->greenHisto->scene()->addItem(&pixmap3);

    ui->blueHisto->setScene(new QGraphicsScene(this));
    ui->blueHisto->scene()->addItem(&pixmap4);

    ui->graphicsView_2->setScene(new QGraphicsScene(this));
    ui->graphicsView_2->scene()->addItem(&pixmapRGB);

    ui->graphicsView_3->setScene(new QGraphicsScene(this));
    ui->graphicsView_3->scene()->addItem(&pixmapDET);


}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startBtn_pressed()
{
    using namespace cv;

    if(video.isOpened())
    {
        ui->startBtn->setText("Start");
        video.release();
        return;
    }

    bool isCamera;
    int cameraIndex = ui->videoEdit->text().toInt(&isCamera);
    if(isCamera)
    {
        if(!video.open(cameraIndex))
        {
            QMessageBox::critical(this,
                                  "Camera Error",
                                  "Make sure you entered a correct camera index,"
                                  "<br>or that the camera is not being accessed by another program!");
            return;
        }
    }
    else
    {
        if(!video.open(ui->videoEdit->text().trimmed().toStdString()))
        {
            QMessageBox::critical(this,
                                  "Video Error",
                                  "Make sure you entered a correct and supported video file path,"
                                  "<br>or a correct RTSP feed URL!");
            return;
        }
    }

    ui->startBtn->setText("Stop");

    Mat frame1;

    video.set(3, 320);
    video.set(4, 240);

    video >> frame1;


    static Rec *rec= new Rec;
    rec->recvideo();

    while(video.isOpened())
    {

        video >> frame1;
        Histogram histogram;


        if(!frame1.empty())
        {

            if(ui->LineBtn->text()=="Normal")               // 엣지
            {
                Linesearch linesearch;
                frame1 = linesearch.Line_edge(frame1);

            }

            cvtColor(frame1, frame1, COLOR_BGR2RGB);
            Mat red_hist, green_hist, blue_hist; // 히스토그램


            // TAB 1
            // ------------------------------------------------------------------------------------ TAB1

            if(ui->tabWidget->currentIndex()==0){



                  QImage qimg(frame1.data,
                          frame1.cols,
                          frame1.rows,
                          frame1.step,
                          QImage::Format_RGB888);




                pixmap.setPixmap( QPixmap::fromImage(qimg));
                ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);

                // 히스토그램


                red_hist = histogram.histg(frame1, 1);
                green_hist = histogram.histg(frame1, 2);
                blue_hist = histogram.histg(frame1, 3);


                if(ui->recBtn->text()=="STOP")
                {

                    cvtColor(frame1,frame1, COLOR_RGB2BGR);
                    rec->writer << frame1;
                    waitKey(cvRound(400.0 / 30));

                }

            }

            // ------------------------------------------------------------------------------------ TAB1

            // TAB 2
            // RGB COLOR split
            // ------------------------------------------------------------------------------------ TAB2
            if(ui->tabWidget->currentIndex()==1){
                bool redbool = ui->RedCheck->checkState();
                bool greenbool = ui->GreenCheck->checkState();
                bool bluebool = ui->BlueCheck->checkState();
                Colorchange colorchange;
                Mat frame2;

                // 3채널
                if(ui->chabtn->text() == "1channel")
                {
                    frame2 = colorchange.colorch(frame1, 1, redbool, greenbool, bluebool);
                }
                else{       // 1채널
                    frame2 = colorchange.colorch(frame1, 3, redbool, greenbool, bluebool);
                }


                QImage qimgRGB(frame2.data,
                          frame2.cols,
                          frame2.rows,
                          frame2.step,
                          QImage::Format_RGB888);

                pixmapRGB.setPixmap( QPixmap::fromImage(qimgRGB));
                ui->graphicsView_2->fitInView(&pixmapRGB, Qt::KeepAspectRatio);


                // 히스토그램
                red_hist = histogram.histg(frame2, 1);
                green_hist = histogram.histg(frame2, 2);
                blue_hist = histogram.histg(frame2, 3);
            }


            // -------------------------------------------------------------------------------------- TAB2



            // TAB3 Detecting
            // -------------------------------------------------------------------------------------- TAB3
            if(ui->tabWidget->currentIndex()==2){

                 if (ui->detectBtn->text() == "STOP"){
                    Detecting detectimg;
                    frame1 = detectimg.detect(frame1);
                 }

                 if (ui->detectBtn2->text() == "STOP"){
                    Detecting detectimg2;
                    frame1 = detectimg2.detect2(frame1);
                 }


                QImage qimgDetect(frame1.data,
                          frame1.cols,
                          frame1.rows,
                          frame1.step,
                          QImage::Format_RGB888);

                pixmapDET.setPixmap( QPixmap::fromImage(qimgDetect));
                ui->graphicsView_3->fitInView(&pixmapDET, Qt::KeepAspectRatio);

                red_hist = histogram.histg(frame1, 1);
                green_hist = histogram.histg(frame1, 2);
                blue_hist = histogram.histg(frame1, 3);

            }


            // -------------------------------------------------------------------------------------- TAB3


            // histogram draw
            // --------------------------------------------------------------------------------------------------


            QImage qimg2(red_hist.data,
                      red_hist.cols,
                      red_hist.rows,
                      red_hist.step,
                      QImage::Format_RGB888);

            QImage qimg3(green_hist.data,
                      green_hist.cols,
                      green_hist.rows,
                      green_hist.step,
                      QImage::Format_RGB888);

            QImage qimg4(blue_hist.data,
                      blue_hist.cols,
                      blue_hist.rows,
                      blue_hist.step,
                      QImage::Format_RGB888);


            pixmap2.setPixmap( QPixmap::fromImage(qimg2));
            ui->redHisto->fitInView(&pixmap2, Qt::KeepAspectRatio);
            pixmap3.setPixmap( QPixmap::fromImage(qimg3));
            ui->greenHisto->fitInView(&pixmap3, Qt::KeepAspectRatio);
            pixmap4.setPixmap( QPixmap::fromImage(qimg4));
            ui->blueHisto->fitInView(&pixmap4, Qt::KeepAspectRatio);

            // --------------------------------------------------------------------------------------------------

        }
        qApp->processEvents();
    }

    ui->startBtn->setText("Start");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(video.isOpened())
    {
        QMessageBox::warning(this,
                             "Warning",
                             "Stop the video before closing the application!");
        event->ignore();
    }
    else
    {
        event->accept();
    }
}
