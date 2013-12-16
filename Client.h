#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include "Netzwerkverbindung.h"

class Client : public Netzwerkverbindung {
    Q_OBJECT
private:
    QTcpSocket socket;
public:
    Client();
    bool verbinden(QHostAddress adresse);
signals:
    verbindungVerloren();
};

#endif // CLIENT_H
