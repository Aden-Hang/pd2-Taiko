#include "mainwindow.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include <QApplication>
#include<QtCore>
#include<QtGui>

int again=0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");


    for(;;)
    {
        MainWindow w;
        w.show();
        if(again==2)break;
        a.exec();
    }





    return 0;

}
