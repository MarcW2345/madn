#include "spiel.h"

Spiel::Spiel(QObject *parent) :
    QObject(parent)
{
}

void Spiel::initSpiel()
{
    for (int i=0;i<4;i++)
        fertig[i]=false;
    anDerReihe=gelb;
}

void Spiel::starteSpiel()
{
    for (int i=0;i<4;i++)
        fertig[i]=false;
    anDerReihe=gelb;
    emit spiele(anDerReihe);
}

 void Spiel::naechster()
 {
     switch (anDerReihe)
     {
         case gelb: anDerReihe=grun;break;
         case grun: anDerReihe=rot;break;
         case rot: anDerReihe=blau;break;
         case blau: anDerReihe=gelb;break;
         case nichtBelegt: anDerReihe=nichtBelegt;break;
     }
     emit spiele(anDerReihe);
     emit timerStart();
 }
