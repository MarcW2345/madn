#include "spielfeld.h"

Spielfeld::Spielfeld(QWidget *parent) :
   Feld(parent)
{
}


void Spielfeld::feldUeberspringen(Zustand _zustaende){
    alterZustand=zustaende;
    zustaende=_zustaende;
    setFigur();
    delayBelegen(200);
}
