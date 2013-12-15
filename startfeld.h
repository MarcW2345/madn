#ifndef STARTFELD_H
#define STARTFELD_H

#include <QLabel>
#include "feld.h"

class Startfeld : public Feld
{
    Q_OBJECT
private:
public:
    explicit Startfeld(QWidget *parent = 0);

signals:

public slots:

};

#endif // STARTFELD_H
