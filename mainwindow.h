#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QGraphicsRectItem>
#include<QtCore>
#include<QtGui>
#include<QWidget>


namespace Ui {
class MainWindow;
}

class QMediaPlayer;

class MainWindow :public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);

    QTimer *timer;

    QTimer * time_drum;

    QTimer * bingo_time;

    int count;
    int red_drumx[8]={1200};
    int blue_drumx[8]={1200};
    int drumy=230;
    int i;
    int score=0;
    int bonus=0;
    int nearest =0;
    int g=0;
    int p=0;
    int correct=0;
    int num[10];
    int luck_num;
    int funny = 0;
    int choose=0;



    ~MainWindow();

private slots:

    void on_startbutton_clicked();

    void Time();

    void on_exitbutton_clicked();

    void time_ch();

    void time_for_drum();

    void run();

    void check();

   void keyPressEvent(QKeyEvent *event);

   void keyReleaseEvent(QKeyEvent *event1);

   void choose_music1();

   void choose_music2();

   void choose_music3();

   void choose_music4();

   void choose_music5();

   void choose_time();

   void on_music1_1_clicked();

   void on_music1_2_clicked();

   void on_music1_3_clicked();

   void on_music1_4_clicked();

   void on_music1_5_clicked();

   void on_time_1_clicked();

   void on_time_2_clicked();

   void on_time_3_clicked();

   void on_time_4_clicked();

   void on_time_5_clicked();

   void on_music2_1_clicked();

   void on_music2_2_clicked();

   void on_music2_3_clicked();

   void on_music2_4_clicked();

   void on_music2_5_clicked();

   void on_music3_1_clicked();

   void on_music3_2_clicked();

   void on_music3_3_clicked();

   void on_music3_4_clicked();

   void on_music3_5_clicked();

   void on_music5_9_clicked();

   void on_music5_1_clicked();

   void on_music5_2_clicked();

   void on_music5_3_clicked();

   void on_music5_4_clicked();

   void on_music5_5_clicked();

   void on_music5_6_clicked();

   void on_music5_7_clicked();

   void on_music5_8_clicked();

   void on_music5_10_clicked();

   void on_music5_11_clicked();

   void on_music5_12_clicked();

   void on_music5_13_clicked();

   void on_music5_14_clicked();

   void on_music5_15_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *mMediaPlayer;
};



#endif // MAINWINDOW_H
