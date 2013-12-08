#include "feld.h"

 feldl::feldl(QWidget* parent) : QLabel(parent)
{
}

 void feldl::mousePressEvent(QMouseEvent *ev)
 {
     emit mousePressed(feldtyp);
 }

 void feldl::change(){
   this->setStyleSheet("image: url(:/felder/grafiken/felder/kreisgrun.svg);");
 }

 void feldl::belegen(){
     //if(farbe==1)
         this->setStyleSheet("image: url(:/felder/grafiken/felder/grunaufgrun.svg);");
 }

 int feldl::getFeldtyp(){return feldtyp;}
 void feldl::setFeldtyp(int t){feldtyp=t;}
