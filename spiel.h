#ifndef SPIEL_H
#define SPIEL_H
#include "spieler.h"
#include "zustand.h"

class Spiel : public QObject
{
    Q_OBJECT
private:
    bool fertig[4];
    Zustand anDerReihe;
public:
    explicit Spiel(QObject *parent = 0);
    Zustand getAnDerReihe() {return anDerReihe;}
public slots:
    void naechster();
    void initSpiel();
    void starteSpiel();
signals:
    void spiele(Zustand);
    void timerStart();

};

#endif // SPIEL_H
