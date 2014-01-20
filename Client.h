#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include "Netzwerkverbindung.h"

class Client : public Netzwerkverbindung {
    Q_OBJECT
private:
    QTcpSocket *socket;
    QString name;
private slots:
    void nachrichtEmpfangen();
public:
    Client(QObject *parent);
    bool verbinden(QHostAddress adresse);
public slots:
    void sendeChat(QString nachricht);
    void sendeWurfeln(quint8 augenzahl);
    void sendeZug(int zug);
signals:
    void verbindungVerloren();
};

#endif // CLIENT_H
