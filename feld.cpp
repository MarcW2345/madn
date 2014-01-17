#include "feld.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <mainwindow.h>

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
      if(zustaende!=nichtBelegt){
      if(figurArt==1){
      if(zustaende==gelb){
          QPixmap figur(":/figuren/grafiken/figuren/gelb.svg");
          setPixmap(figur);}
      else if(zustaende==grun){
          QPixmap figur(":/figuren/grafiken/figuren/grun.svg");
          setPixmap(figur); }
      else if(zustaende==rot){
          QPixmap figur(":/figuren/grafiken/figuren/rot.svg");
          setPixmap(figur);}
      else if(zustaende==blau){
          QPixmap figur(":/figuren/grafiken/figuren/blau.svg");
          setPixmap(figur);}
     }
      else if(figurArt==2)
      {
         if(zustaende==gelb){
            QPixmap figur(":/figuren/grafiken/figuren/schneemanngelb.svg");
            setPixmap(figur);}
         else if(zustaende==grun){
            QPixmap figur(":/figuren/grafiken/figuren/schneemanngrun.svg");
            setPixmap(figur);}
         else if(zustaende==rot){
            QPixmap figur(":/figuren/grafiken/figuren/schneemannrot.svg");
            setPixmap(figur);}
         else if(zustaende==blau){
            QPixmap figur(":/figuren/grafiken/figuren/schneemannblau.svg");
            setPixmap(figur);}
     }
     else if(figurArt==3){
          if(zustaende==gelb){
            QPixmap figur(":/figuren/grafiken/figuren/kugelgelb.svg");
            setPixmap(figur);}
          else if(zustaende==grun){
            QPixmap figur(":/figuren/grafiken/figuren/kugelgrun.svg");
            setPixmap(figur);}
          else if(zustaende==rot){
            QPixmap figur(":/figuren/grafiken/figuren/kugelrot.svg");
            setPixmap(figur);}
          else if(zustaende==blau){
            QPixmap figur(":/figuren/grafiken/figuren/kugelblau.svg");
            setPixmap(figur);}
     }
   }
      else{
          QPixmap figur("");
      setPixmap(figur);}



 }

  void Feld::blinken(){
      QPixmap figur("");
      for(int i=0;i<3;i++)
      {
          if(figurArt==1)
              setPixmap(figur);
          else if(figurArt==2)
              setPixmap(figur);
          else if(figurArt==3)
              setPixmap(figur);
          delayBelegen(180);
          setFigur();
          delayBelegen(180);
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





