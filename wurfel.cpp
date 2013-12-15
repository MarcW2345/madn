#include "wurfel.h"
#include <cmath>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>

int augen_alt;
Wurfel::Wurfel(QWidget *parent) :
    QLabel(parent)
{
}

void delay(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Wurfel::setzeBild(int p)
{
    switch(p)
    {
    case 1:this->setPixmap(QPixmap(QString::fromUtf8(":/wurfel/grafiken/wurfel/wurfel1.svg"))); break;
    case 2:this->setPixmap(QPixmap(QString::fromUtf8(":/wurfel/grafiken/wurfel/wurfel2.svg")));break;
    case 3:this->setPixmap(QPixmap(QString::fromUtf8(":/wurfel/grafiken/wurfel/wurfel3.svg")));break;
    case 4:this->setPixmap(QPixmap(QString::fromUtf8(":/wurfel/grafiken/wurfel/wurfel4.svg")));break;
    case 5:this->setPixmap(QPixmap(QString::fromUtf8(":/wurfel/grafiken/wurfel/wurfel5.svg")));break;
    case 6:this->setPixmap(QPixmap(QString::fromUtf8(":/wurfel/grafiken/wurfel/wurfel6.svg")));break;
    }
}

int Wurfel::wurfeln()
{
    augen=augen_alt;
    while(augen==augen_alt)
       augen=((rand()%6)+1) ;
    augen_alt=augen;
    setzeBild(augen);
    return (augen);
}


void Wurfel::mousePressEvent(QMouseEvent *ev)
{
    wurfeln();
    emit wurfelPressed(augen);
    delay(200);
    wurfeln();
    emit wurfelPressed(augen);
    delay(200);
    wurfeln();
    emit wurfelPressed(augen);
    delay(300);
    wurfeln();
    emit wurfelPressed(augen);
    delay(300);
    wurfeln();
    emit wurfelPressed(augen);
    delay(300);
    wurfeln();
    emit wurfelPressed(augen);
    delay(500);
    wurfeln();
    emit wurfelPressed(augen);
    delay(1000);
    wurfeln();
    emit wurfelPressed(augen);
}
