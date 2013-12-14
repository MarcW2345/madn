#ifndef FELD_H
#define FELD_H

#include <QLabel>

class Feld : public QLabel
{
         Q_OBJECT
private:
    int feldtyp;

public:
    explicit Feld(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    int getFeldtyp();
    void setFeldtyp(int t);

public slots:
    void change();
    void belegen();



signals:
    void mousePressed(int);
};

#endif // FELD_H
