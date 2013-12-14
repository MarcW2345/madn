#ifndef WURFEL_H
#define WURFEL_H

#include <QLabel>

class Wurfel : public QLabel
{
    Q_OBJECT
private:
    int augen;
    void setzeBild(int);
    int wurfeln();
public:
    explicit Wurfel(QWidget *parent = 0);
    int getAugen(){return augen;}

public slots:
    void mousePressEvent(QMouseEvent *ev);

signals:
    void wurfelPressed(int);
};

#endif // WURFEL_H
