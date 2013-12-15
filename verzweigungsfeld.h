#ifndef VERZWEIGUNGSFELD_H
#define VERZWEIGUNGSFELD_H

#include <QLabel>
#include "spielfeld.h"
class Verzweigungsfeld : public Spielfeld
{
    Q_OBJECT
private:
    Zustand farbe;
    int nextZielposition;
public:
    explicit Verzweigungsfeld(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    void setFarbe(Zustand _farbe){farbe=_farbe;}

signals:
    void verzweigungPressed(int,bool,Zustand);
public slots:

};

#endif // VERZWEIGUNGSFELD_H
