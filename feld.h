#ifndef FELDL_H
#define FELDL_H
#include <QLabel>
#include "zustand.h"
class Feld : public QLabel
{
         Q_OBJECT
protected:
    Zustand zustaende;
    Zustand alterZustand;
    int next;
    int feldNr;
    QPixmap figur;
public:
    explicit Feld(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    void setZustand(Zustand _zustaende){zustaende=_zustaende;setFigur();}
    Zustand getZustand(){return zustaende;}
    void setfeldNr(int _feldNr){feldNr=_feldNr;}
    void setNext(int _next);
    void setalterZustand(Zustand _zustaende){alterZustand=_zustaende;}
    virtual int getNext(){return next;}
    void setFigur();
    void feldBelegen(Zustand);
    void feldUeberspringen(Zustand);
    void freistellen();
    void delayBelegen(int);

public:

signals:
    void mousePressed(int,int,Zustand);
};

#endif // FELD_H
