#include "verzweigungsfeld.h"

Verzweigungsfeld::Verzweigungsfeld(QWidget *parent) :
    Spielfeld(parent)
{
}
void Verzweigungsfeld::mousePressEvent(QMouseEvent *ev){
    if(farbe==zustaende)
        emit verzweigungPressed(next,true,zustaende);
    else
        emit verzweigungPressed(next,false,zustaende);
    freistellen();
}
