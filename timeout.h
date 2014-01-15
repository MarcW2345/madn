#ifndef TIMEOUT_H
#define TIMEOUT_H

#include <QObject>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>
#include <iostream>

class Timeout : public QObject
{
    Q_OBJECT
private:
    int sekunden=10;
    void timer();
public:
    explicit Timeout(QObject *parent = 0);
    void setSekunden(int _sekunden){ sekunden=_sekunden;}

signals:
    void sekundeVorbei(int);
    void zeitAbgelaufen();

public slots:
    void starte();
};

#endif // TIMEOUT_H
