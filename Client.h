#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include "Netzwerkverbindung.h"

class Client : public Netzwerkverbindung {
    Q_OBJECT
private:
    QTcpSocket socket;
public:
    Client(QObject *parent);
    bool verbinden(QHostAddress adresse);
signals:
    void verbindungVerloren();
};

#endif // CLIENT_H
