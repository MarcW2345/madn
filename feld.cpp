#include "feld.h"
#include "ui_mainwindow.h"

 Feld::Feld(QWidget* parent) : QLabel(parent)
{
}

// Dies passiert nach einem Mausklick
void Feld::mousePressEvent(QMouseEvent *ev)
{
     emit mousePressed(next,zustaende);
     freistellen();
}


// Stellt dieses Feld frei von einer Figur nach einem Spielzug
 void Feld::freistellen(){
     QPixmap p;
     setPixmap(p);
     zustaende=nichtBelegt;
 }


// Belegt ein Feld mit einer bestimmten Figur
 void Feld::feldBelegen(Zustand _zustaende){
         zustaende=_zustaende;
         setFigur();
 }
// Wird ausschließlich von FeldBelegen aufgerufen und setzt die Grafik der Figur um
 void Feld::setFigur(){
     QPixmap figur;
     if(zustaende==gelb){
         QPixmap figur(":/figuren/grafiken/figuren/gelb.svg");
         setPixmap(figur);
     }
     else if(zustaende==grun){
         QPixmap figur(":/figuren/grafiken/figuren/grun.svg");
         setPixmap(figur);
     }
     else if(zustaende==rot){
         QPixmap figur(":/figuren/grafiken/figuren/rot.svg");
         setPixmap(figur);
     }
     else if(zustaende==blau){
         QPixmap figur(":/figuren/grafiken/figuren/blau.svg");
         setPixmap(figur);
     }
 }

// für die Initialisierung wichtig, aber im Nachhinein nicht mehr zu verwenden!!!!
 void Feld::setNext(int _next){
      next=_next;
 }





