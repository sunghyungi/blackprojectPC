#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>

#include "histogram.h"
#include "linesearch.h"
#include "detecting.h"
#include "colorchange.h"
#include "rec.h"
#include "opencv2/opencv.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_startBtn_pressed();
    void on_LineBtn_pressed();
    void on_upButton_pressed();
    void on_leftButton_pressed();
    void on_rightButton_pressed();
    void on_downButton_pressed();
    void on_extendButton_pressed();
    void on_reduceButton_pressed();
    void on_clockWiseButton_pressed();
    void on_cclockWiseButton_pressed();
    void on_recBtn_pressed();
    void on_detectBtn_pressed();
    void on_chabtn_pressed();
    void on_detectBtn2_pressed();

private:
    Ui::MainWindow *ui;

    QGraphicsPixmapItem pixmap;
    QGraphicsPixmapItem pixmap2;
    QGraphicsPixmapItem pixmap3;
    QGraphicsPixmapItem pixmap4;
    QGraphicsPixmapItem pixmapRGB;
    QGraphicsPixmapItem pixmapDET;
    cv::VideoCapture video;

};
#endif // MAINWINDOW_H


