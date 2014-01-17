#ifndef SPIELFELD_H
#define SPIELFELD_H
#include <QLabel>
#include "feld.h"
#include "zustand.h"
class Spielfeld : public Feld
{
    Q_OBJECT
private:
    int spielfeldNr;
protected:
    Zustand pseudoZustand;
public:
   explicit Spielfeld(QWidget *parent = 0);
   void setSpielfeldNr(int _spielfeldNr){
       spielfeldNr=_spielfeldNr;
   }
   int getSpielfeldNr(){return spielfeldNr;}
   virtual int getnextZielposition(){return 0;}
   void feldUeberspringen(Zustand);
   void setpseudoZustand(Zustand pseudo){ pseudoZustand=pseudo;}
   Zustand getpseudoZustand(){return pseudoZustand;}

signals:


public slots:

};

#endif // SPIELFELD_H
