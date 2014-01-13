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
public:
   explicit Spielfeld(QWidget *parent = 0);
   void setSpielfeldNr(int _spielfeldNr){
       spielfeldNr=_spielfeldNr;
   }
   int getSpielfeldNr(){return spielfeldNr;}
   virtual int getnextZielposition(){return 0;}

signals:


public slots:

};

#endif // SPIELFELD_H
