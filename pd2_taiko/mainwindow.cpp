#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include<stdlib.h>
#include<time.h>
#include<QPixmap>
#include<QLabel>
#include<QColor>
#include<QColorDialog>
#include<QtCore>
#include<QDebug>
#include<QGraphicsScene>
#include<QWidget>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<QTimer>
#include<QList>
#include<QKeyEvent>
#include<QtGui>
#include<QMessageBox>
#include<QOpenGLWidget>
#include<QOpenGLShaderProgram>
#include<QKeyEvent>
#include<QMediaPlayer>
#include<QFileDialog>

extern int again;

QTimer *timer;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);
    //設定隨機
    srand(time(NULL));
    //設定紅鼓、藍鼓的x座標
    for(i=0;i<8;i++)
    {
        red_drumx[i]=(rand()%2000)+1200;
        blue_drumx[i]=(rand()%2000)+1200;
    }
    //設定我的數字
    for(i=0;i<8;i++)
    {
        num[i]=(rand()%79)+1;
    }
    //設定幸運數字
    luck_num=(rand()%79)+1;
    //檢查鼓是否太接近
    check();
    //第一個背景圖
    ui->label1pic->setPixmap(QPixmap(":/117265.jpg"));
    ui->label1pic->setMinimumHeight(1024);
    ui->label1pic->setMinimumWidth(768);
    //第二個背景圖
    ui->label2pic->setPixmap(QPixmap(":/bg.png"));
    ui->label2pic->setMinimumHeight(1024);
    ui->label2pic->setMinimumWidth(768);
    //圓圈目標
    ui->circle->setPixmap(QPixmap(":/attempt_2.png"));
    //刮刮樂圖
    ui->lottery->setPixmap(QPixmap(":/lottery_1.jpg"));
    //設定紅鼓圖
    ui->red_drum1->setPixmap(QPixmap(":/red_drum.jpg"));
    ui->red_drum1_2->setPixmap(QPixmap(":/red_drum.jpg"));
    ui->red_drum1_3->setPixmap(QPixmap(":/red_drum.jpg"));
    ui->red_drum1_4->setPixmap(QPixmap(":/red_drum.jpg"));
    ui->red_drum1_5->setPixmap(QPixmap(":/red_drum.jpg"));
    ui->red_drum1_6->setPixmap(QPixmap(":/red_drum.jpg"));
    ui->red_drum1_7->setPixmap(QPixmap(":/red_drum.jpg"));
    ui->red_drum1_8->setPixmap(QPixmap(":/red_drum.jpg"));
    //ui->red_drum1_9->setPixmap(QPixmap("C:/Users/User/Desktop/Qt/pics/red_drum.jpg"));
    //設定紅鼓位置
    ui->red_drum1->setGeometry(red_drumx[0],drumy,100,100);
    ui->red_drum1_2->setGeometry(red_drumx[1],drumy,100,100);
    ui->red_drum1_3->setGeometry(red_drumx[2],drumy,100,100);
    ui->red_drum1_4->setGeometry(red_drumx[3],drumy,100,100);
    ui->red_drum1_5->setGeometry(red_drumx[4],drumy,100,100);
    ui->red_drum1_6->setGeometry(red_drumx[5],drumy,100,100);
    ui->red_drum1_7->setGeometry(red_drumx[6],drumy,100,100);
    ui->red_drum1_8->setGeometry(red_drumx[7],drumy,100,100);
    // ui->red_drum1_9->setGeometry(100,230,100,100);
    //設定藍鼓圖
    ui->blue_drum1->setPixmap(QPixmap(":/blue_drum.png"));
    ui->blue_drum1_2->setPixmap(QPixmap(":/blue_drum.png"));
    ui->blue_drum1_3->setPixmap(QPixmap(":/blue_drum.png"));
    ui->blue_drum1_4->setPixmap(QPixmap(":/blue_drum.png"));
    ui->blue_drum1_5->setPixmap(QPixmap(":/blue_drum.png"));
    ui->blue_drum1_6->setPixmap(QPixmap(":/blue_drum.png"));
    ui->blue_drum1_7->setPixmap(QPixmap(":/blue_drum.png"));
    ui->blue_drum1_8->setPixmap(QPixmap(":/blue_drum.png"));
    //設定藍鼓位置
    ui->blue_drum1->setGeometry(blue_drumx[0],drumy,100,100);
    ui->blue_drum1_2->setGeometry(blue_drumx[1],drumy,100,100);
    ui->blue_drum1_3->setGeometry(blue_drumx[2],drumy,100,100);
    ui->blue_drum1_4->setGeometry(blue_drumx[3],drumy,100,100);
    ui->blue_drum1_5->setGeometry(blue_drumx[4],drumy,100,100);
    ui->blue_drum1_6->setGeometry(blue_drumx[5],drumy,100,100);
    ui->blue_drum1_7->setGeometry(blue_drumx[6],drumy,100,100);
    ui->blue_drum1_8->setGeometry(blue_drumx[7],drumy,100,100);
    //第二面板物件藏起來
    ui->label2pic->hide();
    ui->timech->hide();
    ui->label->hide();
    ui->label2->hide();
    ui->label2_2->hide();
    ui->label_2->hide();
    ui->bad->hide();
    ui->perfect->hide();
    ui->good->hide();
    ui->circle->hide();
    ui->lottery->hide();
    ui->music1_1->hide();
    ui->music1_2->hide();
    ui->music1_3->hide();
    ui->music1_4->hide();
    ui->music1_5->hide();
    ui->music2_1->hide();
    ui->music2_2->hide();
    ui->music2_3->hide();
    ui->music2_4->hide();
    ui->music2_5->hide();
    ui->music3_1->hide();
    ui->music3_2->hide();
    ui->music3_3->hide();
    ui->music3_4->hide();
    ui->music3_5->hide();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->time_1->hide();
    ui->time_2->hide();
    ui->time_3->hide();
    ui->time_4->hide();
    ui->time_5->hide();
    ui->label_4->hide();

}

void MainWindow::check()
{
    if(red_drumx[0]-red_drumx[1]<=10 || red_drumx[0]-red_drumx[1]>=-10)red_drumx[1]+=50;
    if(red_drumx[0]-red_drumx[2]<=10 || red_drumx[0]-red_drumx[2]>=-10)red_drumx[2]+=50;
    if(red_drumx[0]-red_drumx[3]<=10 || red_drumx[0]-red_drumx[3]>=-10)red_drumx[3]+=50;
    if(red_drumx[0]-red_drumx[4]<=10 || red_drumx[0]-red_drumx[4]>=-10)red_drumx[4]+=50;
    if(red_drumx[0]-red_drumx[5]<=10 || red_drumx[0]-red_drumx[5]>=-10)red_drumx[5]+=50;
    if(red_drumx[0]-red_drumx[6]<=10 || red_drumx[0]-red_drumx[6]>=-10)red_drumx[6]+=50;
    if(red_drumx[0]-red_drumx[7]<=10 || red_drumx[0]-red_drumx[7]>=-10)red_drumx[7]+=50;
    if(red_drumx[1]-red_drumx[2]<=10 || red_drumx[1]-red_drumx[2]>=-10)red_drumx[2]+=50;
    if(red_drumx[1]-red_drumx[3]<=10 || red_drumx[1]-red_drumx[3]>=-10)red_drumx[3]+=50;
    if(red_drumx[1]-red_drumx[4]<=10 || red_drumx[1]-red_drumx[4]>=-10)red_drumx[4]+=50;
    if(red_drumx[1]-red_drumx[5]<=10 || red_drumx[1]-red_drumx[5]>=-10)red_drumx[5]+=50;
    if(red_drumx[1]-red_drumx[6]<=10 || red_drumx[1]-red_drumx[6]>=-10)red_drumx[6]+=50;
    if(red_drumx[1]-red_drumx[7]<=10 || red_drumx[1]-red_drumx[7]>=-10)red_drumx[7]+=50;
    if(red_drumx[2]-red_drumx[3]<=10 || red_drumx[2]-red_drumx[3]>=-10)red_drumx[3]+=50;
    if(red_drumx[2]-red_drumx[4]<=10 || red_drumx[2]-red_drumx[4]>=-10)red_drumx[4]+=50;
    if(red_drumx[2]-red_drumx[5]<=10 || red_drumx[2]-red_drumx[5]>=-10)red_drumx[5]+=50;
    if(red_drumx[2]-red_drumx[6]<=10 || red_drumx[2]-red_drumx[6]>=-10)red_drumx[6]+=50;
    if(red_drumx[2]-red_drumx[7]<=10 || red_drumx[2]-red_drumx[7]>=-10)red_drumx[7]+=50;
    if(red_drumx[3]-red_drumx[4]<=10 || red_drumx[3]-red_drumx[4]>=-10)red_drumx[4]+=50;
    if(red_drumx[3]-red_drumx[5]<=10 || red_drumx[3]-red_drumx[5]>=-10)red_drumx[5]+=50;
    if(red_drumx[3]-red_drumx[6]<=10 || red_drumx[3]-red_drumx[6]>=-10)red_drumx[6]+=50;
    if(red_drumx[3]-red_drumx[7]<=10 || red_drumx[3]-red_drumx[7]>=-10)red_drumx[7]+=50;
    if(red_drumx[4]-red_drumx[5]<=10 || red_drumx[4]-red_drumx[5]>=-10)red_drumx[5]+=50;
    if(red_drumx[4]-red_drumx[6]<=10 || red_drumx[4]-red_drumx[6]>=-10)red_drumx[6]+=50;
    if(red_drumx[4]-red_drumx[7]<=10 || red_drumx[4]-red_drumx[7]>=-10)red_drumx[7]+=50;
    if(red_drumx[5]-red_drumx[6]<=10 || red_drumx[5]-red_drumx[6]>=-10)red_drumx[6]+=50;
    if(red_drumx[5]-red_drumx[7]<=10 || red_drumx[5]-red_drumx[7]>=-10)red_drumx[7]+=50;
    if(red_drumx[6]-red_drumx[7]<=10 || red_drumx[6]-red_drumx[7]>=-10)red_drumx[7]+=50;


    if(blue_drumx[0]-blue_drumx[1]<=10 || blue_drumx[0]-blue_drumx[1]>=-10)blue_drumx[1]+=50;
    if(blue_drumx[0]-blue_drumx[2]<=10 || blue_drumx[0]-blue_drumx[2]>=-10)blue_drumx[2]+=50;
    if(blue_drumx[0]-blue_drumx[3]<=10 || blue_drumx[0]-blue_drumx[3]>=-10)blue_drumx[3]+=50;
    if(blue_drumx[0]-blue_drumx[4]<=10 || blue_drumx[0]-blue_drumx[4]>=-10)blue_drumx[4]+=50;
    if(blue_drumx[0]-blue_drumx[5]<=10 || blue_drumx[0]-blue_drumx[5]>=-10)blue_drumx[5]+=50;
    if(blue_drumx[0]-blue_drumx[6]<=10 || blue_drumx[0]-blue_drumx[6]>=-10)blue_drumx[6]+=50;
    if(blue_drumx[0]-blue_drumx[7]<=10 || blue_drumx[0]-blue_drumx[7]>=-10)blue_drumx[7]+=50;
    if(blue_drumx[1]-blue_drumx[2]<=10 || blue_drumx[1]-blue_drumx[2]>=-10)blue_drumx[2]+=50;
    if(blue_drumx[1]-blue_drumx[3]<=10 || blue_drumx[1]-blue_drumx[3]>=-10)blue_drumx[3]+=50;
    if(blue_drumx[1]-blue_drumx[4]<=10 || blue_drumx[1]-blue_drumx[4]>=-10)blue_drumx[4]+=50;
    if(blue_drumx[1]-blue_drumx[5]<=10 || blue_drumx[1]-blue_drumx[5]>=-10)blue_drumx[5]+=50;
    if(blue_drumx[1]-blue_drumx[6]<=10 || blue_drumx[1]-blue_drumx[6]>=-10)blue_drumx[6]+=50;
    if(blue_drumx[1]-blue_drumx[7]<=10 || blue_drumx[1]-blue_drumx[7]>=-10)blue_drumx[7]+=50;
    if(blue_drumx[2]-blue_drumx[3]<=10 || blue_drumx[2]-blue_drumx[3]>=-10)blue_drumx[3]+=50;
    if(blue_drumx[2]-blue_drumx[4]<=10 || blue_drumx[2]-blue_drumx[4]>=-10)blue_drumx[4]+=50;
    if(blue_drumx[2]-blue_drumx[5]<=10 || blue_drumx[2]-blue_drumx[5]>=-10)blue_drumx[5]+=50;
    if(blue_drumx[2]-blue_drumx[6]<=10 || blue_drumx[2]-blue_drumx[6]>=-10)blue_drumx[6]+=50;
    if(blue_drumx[2]-blue_drumx[7]<=10 || blue_drumx[2]-blue_drumx[7]>=-10)blue_drumx[7]+=50;
    if(blue_drumx[3]-blue_drumx[4]<=10 || blue_drumx[3]-blue_drumx[4]>=-10)blue_drumx[4]+=50;
    if(blue_drumx[3]-blue_drumx[5]<=10 || blue_drumx[3]-blue_drumx[5]>=-10)blue_drumx[5]+=50;
    if(blue_drumx[3]-blue_drumx[6]<=10 || blue_drumx[3]-blue_drumx[6]>=-10)blue_drumx[6]+=50;
    if(blue_drumx[3]-blue_drumx[7]<=10 || blue_drumx[3]-blue_drumx[7]>=-10)blue_drumx[7]+=50;
    if(blue_drumx[4]-blue_drumx[5]<=10 || blue_drumx[4]-blue_drumx[5]>=-10)blue_drumx[5]+=50;
    if(blue_drumx[4]-blue_drumx[6]<=10 || blue_drumx[4]-blue_drumx[6]>=-10)blue_drumx[6]+=50;
    if(blue_drumx[4]-blue_drumx[7]<=10 || blue_drumx[4]-blue_drumx[7]>=-10)blue_drumx[7]+=50;
    if(blue_drumx[5]-blue_drumx[6]<=10 || blue_drumx[5]-blue_drumx[6]>=-10)blue_drumx[6]+=50;
    if(blue_drumx[5]-blue_drumx[7]<=10 || blue_drumx[5]-blue_drumx[7]>=-10)blue_drumx[7]+=50;
    if(blue_drumx[6]-blue_drumx[7]<=10 || blue_drumx[6]-blue_drumx[7]>=-10)blue_drumx[7]+=50;
    ui->bad->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::choose_time()
{
    ui->label1pic->setPixmap(QPixmap(":clock.jpg"));
    ui->time_1->show();
    ui->time_2->show();
    ui->time_3->show();
    ui->time_5->show();
    ui->label_4->show();
}

void MainWindow::choose_music1()
{
    ui->label1pic->setPixmap(QPixmap(":/beautiful.jpg"));
    ui->music1_1->show();
    ui->music1_2->show();
    ui->music1_3->show();
    ui->music1_4->show();
    ui->music1_5->show();
    ui->label_3->show();
}

void MainWindow::choose_music2()
{
    ui->label1pic->setPixmap(QPixmap(":/beautiful.jpg"));
    ui->music2_1->show();
    ui->music2_2->show();
    ui->music2_3->show();
    ui->music2_4->show();
    ui->music2_5->show();
    ui->label_3->show();
}

void MainWindow::choose_music3()
{
    ui->label1pic->setPixmap(QPixmap(":/beautiful.jpg"));
    ui->music3_1->show();
    ui->music3_2->show();
    ui->music3_3->show();
    ui->music3_4->show();
    ui->music3_5->show();
    ui->label_3->show();
}

void MainWindow::choose_music5()
{
    ui->label1pic->setPixmap(QPixmap(":/beautiful.jpg"));
    ui->music5_1->show();
    ui->music5_2->show();
    ui->music5_3->show();
    ui->music5_4->show();
    ui->music5_5->show();
    ui->music5_6->show();
    ui->music5_7->show();
    ui->music5_8->show();
    ui->music5_9->show();
    ui->music5_10->show();
    ui->music5_11->show();
    ui->music5_12->show();
    ui->music5_13->show();
    ui->music5_14->show();
    ui->music5_15->show();
    ui->label_3->show();
}

void MainWindow::on_startbutton_clicked()
{
    ui->startbutton->hide();
    ui->exitbutton->hide();
    choose_time();
}

void MainWindow::on_exitbutton_clicked()
{
    again=2;
    close();
}

void MainWindow::Time()
{
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(time_ch()));
    timer->start();

}

void MainWindow::time_ch()
{
    count--;
    ui->timech->setText(QString::number(count));
    if(count==0)
    {
        this->close();
        Dialog dialog;
        dialog.exec();

    }
}

void MainWindow::time_for_drum()
{

    time_drum = new QTimer(this);
    time_drum->setInterval(10);
    connect(time_drum,SIGNAL(timeout()),this,SLOT(run()));
    time_drum->start();
}

void MainWindow::run()
{
   ui->scores->setText(QString::number(score));
   ui->red_drum1->setGeometry(red_drumx[0],drumy,100,100);
   ui->red_drum1_2->setGeometry(red_drumx[1],drumy,100,100);
   ui->red_drum1_3->setGeometry(red_drumx[2],drumy,100,100);
   ui->red_drum1_4->setGeometry(red_drumx[3],drumy,100,100);
   ui->red_drum1_5->setGeometry(red_drumx[4],drumy,100,100);
   ui->red_drum1_6->setGeometry(red_drumx[5],drumy,100,100);
   ui->red_drum1_7->setGeometry(red_drumx[6],drumy,100,100);
   ui->red_drum1_8->setGeometry(red_drumx[7],drumy,100,100);

   ui->blue_drum1->setGeometry(blue_drumx[0],drumy,100,100);
   ui->blue_drum1_2->setGeometry(blue_drumx[1],drumy,100,100);
   ui->blue_drum1_3->setGeometry(blue_drumx[2],drumy,100,100);
   ui->blue_drum1_4->setGeometry(blue_drumx[3],drumy,100,100);
   ui->blue_drum1_5->setGeometry(blue_drumx[4],drumy,100,100);
   ui->blue_drum1_6->setGeometry(blue_drumx[5],drumy,100,100);
   ui->blue_drum1_7->setGeometry(blue_drumx[6],drumy,100,100);
   ui->blue_drum1_8->setGeometry(blue_drumx[7],drumy,100,100);

   for(i=0;i<8;i++)
   {
       red_drumx[i]-=10;
       blue_drumx[i]-=10;
       if(red_drumx[i]<=-150)
       {
           red_drumx[i]=(rand()%2000)+1200;
       }

       if(blue_drumx[i]<=-150)
       {
           blue_drumx[i]=(rand()%2000)+1200;
       }


   }
   check();
   if(red_drumx[0]<50 || red_drumx[1]<50 || red_drumx[2]<50 || red_drumx[3]<50 || red_drumx[4]<50 || red_drumx[5]<50 || red_drumx[6]<50 || red_drumx[7]<50)
   {
       ui->bad->show();
       bonus=0;
       ui->bonuss->setText(QString::number(bonus));

   }

   if(blue_drumx[0]<50 || blue_drumx[1]<50 || blue_drumx[2]<50 || blue_drumx[3]<50 || blue_drumx[4]<50 || blue_drumx[5]<50 || blue_drumx[6]<50 || blue_drumx[7]<50)
   {
       ui->bad->show();
       bonus=0;
       ui->bonuss->setText(QString::number(bonus));

   }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    for(i=0;i<8;i++)
    {
        if(event->key()==Qt::Key_R && red_drumx[i]<=120 && red_drumx[i]>=80)
        {
            ui->perfect->show();
            p=1;
            g=0;
            correct++;
            score+=2;
            if(bonus>=1)
            {
                score+=bonus;
            }
            ui->scores->setText(QString::number(score));
            bonus++;
            ui->bonuss->setText(QString::number(bonus));
            red_drumx[i]=(rand()%2000)+1200;
            check();
        }
        if(event->key()==Qt::Key_B && blue_drumx[i]<=120 && blue_drumx[i]>=80)
        {
            ui->perfect->show();
            p=1;
            g=0;
            correct++;
            score+=2;
            if(bonus>=1)
            {
                score+=bonus;
            }
            ui->scores->setText(QString::number(score));
            bonus++;
            ui->bonuss->setText(QString::number(bonus));
            blue_drumx[i]=(rand()%2000)+1200;
            check();
        }
        if(event->key()==Qt::Key_R && red_drumx[i]>=120 && red_drumx[i]<=150)
        {
            ui->good->show();
            p=0;
            g=1;
            correct++;
            score+=1;
            if(bonus>=1)
            {
                score+=bonus;
            }
            ui->scores->setText(QString::number(score));
            bonus++;
            ui->bonuss->setText(QString::number(bonus));
            red_drumx[i]=(rand()%2000)+1200;
            check();
        }
        if(event->key()==Qt::Key_B && blue_drumx[i]>=120 && blue_drumx[i]<=150)
        {
            ui->good->show();
            p=0;
            g=1;
            correct++;
            score+=1;
            if(bonus>=1)
            {
                score+=bonus;
            }
            ui->scores->setText(QString::number(score));
            bonus++;
            ui->bonuss->setText(QString::number(bonus));
            blue_drumx[i]=(rand()%2000)+1200;
            check();
        }
        if(event->key()==Qt::Key_R && red_drumx[i]>=50 && red_drumx[i]<=80)
        {
            ui->good->show();
            p=0;
            g=1;
            correct++;
            score+=1;
            if(bonus>=1)
            {
                score+=bonus;
            }
            ui->scores->setText(QString::number(score));
            bonus++;
            ui->bonuss->setText(QString::number(bonus));
            red_drumx[i]=(rand()%2000)+1200;
            check();
        }
        if(event->key()==Qt::Key_B && blue_drumx[i]>=50 && blue_drumx[i]<=80)
        {
            ui->good->show();
            p=0;
            g=1;
            correct++;
            score+=1;
            if(bonus>=1)
            {
                score+=bonus;
            }
            ui->scores->setText(QString::number(score));
            bonus++;
            ui->bonuss->setText(QString::number(bonus));
            blue_drumx[i]=(rand()%2500)+1200;
            check();
        }
    }
    if(correct>=4)
    {
        ui->mynum_1->setText(QString::number(num[0]));
        if(luck_num==num[0]&&correct==4)score*=2;
    }
    if(correct>=8)
    {
        ui->mynum_2->setText(QString::number(num[1]));
        if(luck_num==num[1]&&correct==8)score*=2;
    }
    if(correct>=12)
    {
        ui->mynum_3->setText(QString::number(num[2]));
        if(luck_num==num[2]&&correct==12)score*=2;
    }
    if(correct>=16)
    {
        ui->mynum_4->setText(QString::number(num[3]));
        if(luck_num==num[3]&&correct==16)score*=2;
    }
    if(correct>=20)
    {
        ui->mynum_5->setText(QString::number(num[4]));
        if(luck_num==num[4]&&correct==20)score*=2;
    }
    if(correct>=24)
    {
        ui->mynum_6->setText(QString::number(num[5]));
        if(luck_num==num[5]&&correct==24)score*=2;
    }
    if(correct>=28)
    {
        ui->mynum_7->setText(QString::number(num[6]));
        if(luck_num==num[6]&&correct==28)score*=2;
    }
    if(correct>=32)
    {
        ui->mynum_8->setText(QString::number(num[7]));
        if(luck_num==num[7]&&correct==32)score*=2;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event1)
{
    if(funny==0)
    {
        if(event1->key()==Qt::Key_R && g==1)
        {
            ui->good->hide();
            g=0;
        }
        if(event1->key()==Qt::Key_B && g==1)
        {
            ui->good->hide();
            g=0;
        }
        if(event1->key()==Qt::Key_R && p==1)
        {
            ui->perfect->hide();
            p=0;
        }
        if(event1->key()==Qt::Key_B && p==1)
        {
            ui->perfect->hide();
            p=0;
        }
    }
}

void MainWindow::on_time_1_clicked()
{
    count=30;
    ui->time_1->hide();
    ui->time_2->hide();
    ui->time_3->hide();
    ui->time_4->hide();
    ui->time_5->hide();
    ui->label_4->hide();
    choose_music1();
}

void MainWindow::on_time_2_clicked()
{
    count=60;
    ui->time_1->hide();
    ui->time_2->hide();
    ui->time_3->hide();
    ui->time_4->hide();
    ui->time_5->hide();
    ui->label_4->hide();
    choose_music2();
}

void MainWindow::on_time_3_clicked()
{
    count=90;
    ui->time_1->hide();
    ui->time_2->hide();
    ui->time_3->hide();
    ui->time_4->hide();
    ui->time_5->hide();
    ui->label_4->hide();
    choose_music3();
}

void MainWindow::on_time_5_clicked()
{
    ui->time_1->hide();
    ui->time_2->hide();
    ui->time_3->hide();
    ui->time_4->hide();
    ui->time_5->hide();
    ui->label_4->hide();
    choose_music5();
}

void MainWindow::on_music1_1_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("qrc:/Maroon5_Love Somebody (30s).mp3"));
    mMediaPlayer->play();
    ui->music1_1->hide();
    ui->music1_2->hide();
    ui->music1_3->hide();
    ui->music1_4->hide();
    ui->music1_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music1_2_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("qrc:/don't_be_friend_again (30s).mp3"));
    mMediaPlayer->play();
    ui->music1_1->hide();
    ui->music1_2->hide();
    ui->music1_3->hide();
    ui->music1_4->hide();
    ui->music1_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music1_3_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("qrc:/---Tia Lee------Not Good Enough-Official Music Video HD (30s).mp3"));
    mMediaPlayer->play();
    ui->music1_1->hide();
    ui->music1_2->hide();
    ui->music1_3->hide();
    ui->music1_4->hide();
    ui->music1_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music1_4_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/JessieJ_Flashlight (30s).mp3"));
    mMediaPlayer->play();
    ui->music1_1->hide();
    ui->music1_2->hide();
    ui->music1_3->hide();
    ui->music1_4->hide();
    ui->music1_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music1_5_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Green Day - 21 Guns [Official Music Video] (30s).mp3"));
    mMediaPlayer->play();
    ui->music1_1->hide();
    ui->music1_2->hide();
    ui->music1_3->hide();
    ui->music1_4->hide();
    ui->music1_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();

}

void MainWindow::on_music2_1_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Ellie Goulding_Love_Me_Like_You_Do(60s).mp3"));
    mMediaPlayer->play();
    ui->music2_1->hide();
    ui->music2_2->hide();
    ui->music2_3->hide();
    ui->music2_4->hide();
    ui->music2_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music2_2_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/hear_the_sound_of_raining(60s).mp3"));
    mMediaPlayer->play();
    ui->music2_1->hide();
    ui->music2_2->hide();
    ui->music2_3->hide();
    ui->music2_4->hide();
    ui->music2_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music2_3_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/JJ Lin_Twilight_(Official_HD_MV)(60s).mp3"));
    mMediaPlayer->play();
    ui->music2_1->hide();
    ui->music2_2->hide();
    ui->music2_3->hide();
    ui->music2_4->hide();
    ui->music2_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music2_4_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/JJ_sorry_no_if (60s).mp3"));
    mMediaPlayer->play();
    ui->music2_1->hide();
    ui->music2_2->hide();
    ui->music2_3->hide();
    ui->music2_4->hide();
    ui->music2_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music2_5_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/you are what man (60s).mp3"));
    mMediaPlayer->play();
    ui->music2_1->hide();
    ui->music2_2->hide();
    ui->music2_3->hide();
    ui->music2_4->hide();
    ui->music2_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music3_1_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Della-- [ -------Love Myself More ] Official Music Video - ------------- (90s).mp3"));
    mMediaPlayer->play();
    ui->music3_1->hide();
    ui->music3_2->hide();
    ui->music3_3->hide();
    ui->music3_4->hide();
    ui->music3_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music3_2_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Maroon5_Animals (90s).mp3"));
    mMediaPlayer->play();
    ui->music3_1->hide();
    ui->music3_2->hide();
    ui->music3_3->hide();
    ui->music3_4->hide();
    ui->music3_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music3_3_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Maroon5_Maps (90S).mp3"));
    mMediaPlayer->play();
    ui->music3_1->hide();
    ui->music3_2->hide();
    ui->music3_3->hide();
    ui->music3_4->hide();
    ui->music3_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music3_4_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Maroon5_Payphone (90s).mp3"));
    mMediaPlayer->play();
    ui->music3_1->hide();
    ui->music3_2->hide();
    ui->music3_3->hide();
    ui->music3_4->hide();
    ui->music3_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music3_5_clicked()
{
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/MP_I_am_still_love_you (90s).mp3"));
    mMediaPlayer->play();
    ui->music3_1->hide();
    ui->music3_2->hide();
    ui->music3_3->hide();
    ui->music3_4->hide();
    ui->music3_5->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_1_clicked()
{
    count=229;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Maroon5_Love Somebody.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_2_clicked()
{
    count=257;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/don't_be_friend_again.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_3_clicked()
{
    count=219;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/---Tia Lee------Not Good Enough-Official Music Video HD.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_4_clicked()
{
    count=209;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/JessieJ_Flashlight.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_5_clicked()
{
    count=326;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Green Day - 21 Guns [Official Music Video].mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_6_clicked()
{
    count=250;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Ellie Goulding - Love Me Like You Do.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_7_clicked()
{
    count=279;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/hear_the_sound_of_raining.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_8_clicked()
{
    count=312;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/JJ Lin - Twilight (Official HD MV).mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_9_clicked()
{
    count=298;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/JJ_sorry_no_if.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_10_clicked()
{
    count=287;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/you are what man.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_11_clicked()
{
    count=260;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Della-- [ -------Love Myself More ] Official Music Video - -------------.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_12_clicked()
{
    count=280;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Maroon5_Animals.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_13_clicked()
{
    count=208;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Maroon5_Maps.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_14_clicked()
{
    count=231;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/Maroon5_Payphone.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}

void MainWindow::on_music5_15_clicked()
{
    count=289;
    ui->label1pic->hide();
    mMediaPlayer->setMedia(QUrl("C:/Users/User/Documents/drumNew/MP_I_am_still_love_you.mp3"));
    mMediaPlayer->play();
    ui->music5_1->hide();
    ui->music5_2->hide();
    ui->music5_3->hide();
    ui->music5_4->hide();
    ui->music5_5->hide();
    ui->music5_6->hide();
    ui->music5_7->hide();
    ui->music5_8->hide();
    ui->music5_9->hide();
    ui->music5_10->hide();
    ui->music5_11->hide();
    ui->music5_12->hide();
    ui->music5_13->hide();
    ui->music5_14->hide();
    ui->music5_15->hide();
    ui->label_3->hide();
    ui->label2pic->show();
    ui->label->show();
    ui->label2->show();
    ui->label2_2->show();
    ui->timech->show();
    ui->circle->show();
    ui->lottery->show();
    ui->label_2->show();
    ui->lucknum->setText(QString::number(luck_num));
    time_for_drum();
    Time();
}


