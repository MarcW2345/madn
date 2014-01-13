#include "feld.h"
#include "ui_mainwindow.h"
#include <QTime>
 Feld::Feld(QWidget* parent) : QLabel(parent)
{
}

// Dies passiert nach einem Mausklick
void Feld::mousePressEvent(QMouseEvent *ev)
{
    ev=ev;
    if(zustaende!=nichtBelegt)
        emit mousePressed(next,feldNr,zustaende);
}


// Stellt dieses Feld frei von einer Figur nach einem Spielzug
 void Feld::freistellen(){
     QPixmap p;
     setPixmap(p);
     setZustand(alterZustand);
 }

 void Feld::feldUeberspringen(Zustand _zustaende){
     alterZustand=zustaende;
     zustaende=_zustaende;
     setFigur();
     delayBelegen(200);
 }

// Belegt ein Feld mit einer bestimmten Figur
 void Feld::feldBelegen(Zustand _zustaende){
    alterZustand=nichtBelegt;
    zustaende=_zustaende;
    setFigur();
    delayBelegen(200);
 }

// Wird ausschließlich von FeldBelegen aufgerufen und setzt die Grafik der Figur um
 void Feld::setFigur(){
     QPixmap figur;
     if(zustaende==gelb){
         QPixmap figur(":/figuren/grafiken/figuren/kugelgelb.svg");
         setPixmap(figur);
     }
     else if(zustaende==grun){
         QPixmap figur(":/figuren/grafiken/figuren/schneemanngrun.svg");
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

 void Feld::delayBelegen(int n)
 {
     QTime dieTime= QTime::currentTime().addMSecs(n);
     while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
 }





