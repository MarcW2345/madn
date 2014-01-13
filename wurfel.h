#ifndef WURFEL_H
#define WURFEL_H

#include <QLabel>
#include "zustand.h"

class Wurfel : public QLabel
{
    Q_OBJECT
public:
    explicit Wurfel(QWidget *parent = 0);
    int getAugen(){return augen;}

private:
    int augen_alt;
    int augen_alt2;
    int augen;
    Zustand spielerFarbe;
    bool darfWurfeln;
    void setzeBild(int);
    int wurfeln();
    void delay(int);

public slots:
    void mousePressEvent(QMouseEvent*);
    void darfWurfelnSlot();
    void setzeFarbe(Zustand);
    void hatGewurfelt(int);

signals:
    void wurfelPressed(int);
    void setzeAugen(int);
    void habeGewurfelt(int);
    void zugPhase(int);
};

#endif // WURFEL_H
