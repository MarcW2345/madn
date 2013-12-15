#ifndef FELDL_H
#define FELDL_H
#include <QLabel>
#include "zustand.h"
class Feld : public QLabel
{
         Q_OBJECT
protected:
    Zustand zustaende;
    int next;
    int feldNr;
    QPixmap figur;
public:
    explicit Feld(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    void setZustand(Zustand _zustaende){zustaende=_zustaende;}
    Zustand getZustand(){return zustaende;}
    void setNext(int _next);
    int getNext(){return next;}
    void setFigur();
    void freistellen();

public slots:
    void feldBelegen(Zustand);
signals:
    void mousePressed(int,Zustand);
};

#endif // FELD_H
