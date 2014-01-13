#include "verzweigungsfeld.h"

Verzweigungsfeld::Verzweigungsfeld(QWidget *parent) :
    Spielfeld(parent)
{
}
void Verzweigungsfeld::mousePressEvent(QMouseEvent *ev){
    if(farbe==zustaende)
        emit mousePressed(next,feldNr,zustaende);
    else
        emit mousePressed(next,feldNr,zustaende);
}

int Verzweigungsfeld::getNext(){
    if(farbe==zustaende)
        return 0;
    else
        return next;
}

