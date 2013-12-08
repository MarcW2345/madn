#include "wurfel.h"
#include <cmath>


wurfel::wurfel(QWidget *parent) :
    QLabel(parent)
{
}

int wurfel::wurfeln()
{
    augen=((rand()%6)+1) ;
    return (augen);
}


void wurfel::mousePressEvent(QMouseEvent *ev)
{
    wurfeln();
    switch(getAugen()){
    case 1: this->setPixmap(QPixmap(QString::fromUtf8(":/wurfel/grafiken/wurfel/wurfel1.svg"))); break;
    case 2:this->setPixmap(QPixmap(QString::fromUtf8(":/wurfel/grafiken/wurfel/wurfel2.svg")));break;
    case 3:this->setPixmap(QPixmap(QString::fromUtf8(":/wurfel/grafiken/wurfel/wurfel3.svg")));break;
    case 4:this->setPixmap(QPixmap(QString::fromUtf8(":/wurfel/grafiken/wurfel/wurfel4.svg")));break;
    case 5:this->setPixmap(QPixmap(QString::fromUtf8(":/wurfel/grafiken/wurfel/wurfel5.svg")));break;
    case 6:this->setPixmap(QPixmap(QString::fromUtf8(":/wurfel/grafiken/wurfel/wurfel6.svg")));break;
    }
    emit wurfelPressed(getAugen());
}
