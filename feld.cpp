#include "feld.h"

 Feld::Feld(QWidget* parent) : QLabel(parent)
{
}

 void Feld::mousePressEvent(QMouseEvent *ev)
 {
     emit mousePressed(feldtyp);
 }

 void Feld::change(){
   this->setStyleSheet("image: url(:/felder/grafiken/felder/kreisgrun.svg);");
 }

 void Feld::belegen(){
     //if(farbe==1)
         this->setStyleSheet("image: url(:/felder/grafiken/felder/grunaufgrun.svg);");
 }

 int Feld::getFeldtyp(){return feldtyp;}
 void Feld::setFeldtyp(int t){feldtyp=t;}
