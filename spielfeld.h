#ifndef SPIELFELD_H
#define SPIELFELD_H

#include "feld.h"

class Spielfeld : public Feld
{
    Q_OBJECT
public:
    explicit Spielfeld(QWidget *parent = 0);

signals:

public slots:

};

#endif // SPIELFELD_H
