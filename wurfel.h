#ifndef WURFEL_H
#define WURFEL_H

#include <QLabel>

class wurfel : public QLabel
{
    Q_OBJECT
private:
    int augen;
    int wurfeln();
public:
    explicit wurfel(QWidget *parent = 0);
    int getAugen(){return augen;}

public slots:
    void mousePressEvent(QMouseEvent *ev);

signals:
    void wurfelPressed(int);
};

#endif // WURFEL_H
