#include "mainwindow.h"
#include "ui_mainwindow.h"




void MainWindow::on_LineBtn_pressed()
{
    if(ui->LineBtn->text()=="Linesearch")
    {
        ui->LineBtn->setText("Normal");
        ui->LineBtn->setStyleSheet("#LineBtn{padding: 2px; background-color: gray; font: bold italic 15px; color:white;}");



    }
    else{
        ui->LineBtn->setText("Linesearch");
         ui->LineBtn->setStyleSheet("#LineBtn{padding: 2px; background-color: green; font: bold italic 15px; color:white;}");
    }
}


// 위젯 이동 함수
#define I 4
void MainWindow::on_upButton_pressed()
{
    ui->graphicsView->move(ui->graphicsView->x(), ui->graphicsView->y()-I);
}

void MainWindow::on_leftButton_pressed()
{
    ui->graphicsView->move(ui->graphicsView->x()-I, ui->graphicsView->y());
}

void MainWindow::on_rightButton_pressed()
{
    ui->graphicsView->move(ui->graphicsView->x()+I, ui->graphicsView->y());
}

void MainWindow::on_downButton_pressed()
{
    ui->graphicsView->move(ui->graphicsView->x(), ui->graphicsView->y()+I);
}

// 위젯 확장, 축소 함수

void MainWindow::on_extendButton_pressed()
{
    ui->graphicsView->setFixedSize(ui->graphicsView->width()+2, ui->graphicsView->height()+3);
}

void MainWindow::on_reduceButton_pressed()
{
    ui->graphicsView->setFixedSize(ui->graphicsView->width()-2, ui->graphicsView->height()-3);
}

void MainWindow::on_clockWiseButton_pressed()
{
    ui->graphicsView->rotate(10);
}


void MainWindow::on_cclockWiseButton_pressed()
{
    ui->graphicsView->rotate(-10);
}



void MainWindow::on_detectBtn_pressed()
{
    if(ui->detectBtn->text()=="Detect")
    {
        ui->detectBtn->setText("STOP");
    }
    else{
        ui->detectBtn->setText("Detect");
    }
}

void MainWindow::on_chabtn_pressed()
{
    if(ui->chabtn->text() == "1channel")
    {
        ui->chabtn->setText("3channel");
    }
    else{
        ui->chabtn->setText("1channel");
    }
}



void MainWindow::on_detectBtn2_pressed()
{
    if(ui->detectBtn2->text()=="Detect")
    {
        ui->detectBtn2->setText("STOP");
    }
    else{
        ui->detectBtn2->setText("Detect");
    }
}



void MainWindow::on_recBtn_pressed()
{
    if(ui->recBtn->text()=="REC")
    {
        ui->recBtn->setText("STOP");
        ui->recBtn->setStyleSheet("#recBtn{background-color:black; color:white; border-radius: 10px; padding: 2px; font: bold italic 20px;}");


    }
    else{
        ui->recBtn->setText("REC");
        ui->recBtn->setStyleSheet("#recBtn{background-color:red; color:white; border-radius: 10px; padding: 2px; font: bold italic 20px;}");

    }
}

