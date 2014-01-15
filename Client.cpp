
#include "Client.h"

#include <QHostAddress>
#include <iostream>

Client::Client(QObject *parent) {
    socket = 0;
}

bool Client::verbinden(QHostAddress adresse) {
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(nachrichtEmpfangen()));
    socket->connectToHost(adresse, 60123);
    bool verbunden = socket->waitForConnected();
    if (!verbunden) {
        std::cerr << "Client::verbinden : nicht verbunden : " << socket->errorString().toStdString();
        delete socket;
        socket = 0;
    }
    return verbunden;
}

void Client::nachrichtEmpfangen() {
    while (socket->canReadLine()) {
        QByteArray nachricht = socket->readLine();
        emit chatEmpfangen(QString::fromUtf8(nachricht));
    }
}

void Client::sendeChat(QString nachricht) {
    socket->write(nachricht.toUtf8());
    socket->write("\n");
}

void Client::sendeWurfeln(quint8 augenzahl) {

}

void Client::sendeZug(int zug) {

}
