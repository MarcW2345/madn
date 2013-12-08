#ifndef FELDL_H
#define FELDL_H

#include <QLabel>

class feldl : public QLabel
{
         Q_OBJECT
private:
    int feldtyp;

public:
    explicit feldl(QWidget *parent = 0);
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
