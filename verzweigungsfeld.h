#ifndef VERZWEIGUNGSFELD_H
#define VERZWEIGUNGSFELD_H

#include <QLabel>
#include "spielfeld.h"
class Verzweigungsfeld : public Spielfeld
{
    Q_OBJECT
private:
    Zustand farbe; // Verzweigungsfeld, damit klar ist wohin es weitergeht, also welche Zielfelder
    int nextZielposition;
public:
    explicit Verzweigungsfeld(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    void setFarbe(Zustand _farbe){farbe=_farbe;}
    int getNext();
    void setnextZielposition(int _nextZielposition){nextZielposition=_nextZielposition;}
    int getnextZielposition(){return nextZielposition;}

signals:
public slots:

};

#endif // VERZWEIGUNGSFELD_H
