#ifndef NETZWERKVERBINDUNG_H
#define NETZWERKVERBINDUNG_H

#include <QObject>

class Zug;

class Netzwerkverbindung : public QObject {
    Q_OBJECT
public slots:
    sendeChat(QString nachricht) = 0;
    sendeWurfeln(int augenzahl) = 0;
    sendeZug(Zug zug) = 0;
signals:
    chatEmpfangen(QString nachricht);
    wurfelnEmpfangen(int augenzahl);
    zugEmpfangen(Zug zug);
    spielerBeigetreten(QString name);
    spielerVerschwunden(QString name);
};

#endif // NETZWERKVERBINDUNG_H
