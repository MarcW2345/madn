
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
        QString nachricht = QString::fromUtf8(socket->readLine());
        QString typ = nachricht.section(QString::fromAscii("\x1F"),0,0);
        if (typ == QString::fromAscii("chat")) {
            QString absender = nachricht.section(QString::fromAscii("\x1F"),1,1);
            QString text = nachricht.section(QString::fromAscii("\x1F"),2,-1);
            emit chatEmpfangen(QString::fromAscii("<b>") + absender + QString::fromAscii("</b>: ") + text);
        } else if (typ == QString::fromAscii("wurf")) {
            int augenzahl = nachricht.section(QString::fromAscii("\x1F"),1,1).toInt(0, 10);
            emit wurfelnEmpfangen(augenzahl);
        }
    }
}

void Client::sendeChat(QString nachricht) {
    socket->write("chat");
    socket->write("\x1F");
    socket->write(name.toUtf8());
    socket->write("\x1F");
    socket->write(nachricht.toUtf8());
    socket->write("\n");
}

void Client::sendeWurfeln(int augenzahl) {
    socket->write("wurf");
    socket->write("\x1F");
    socket->write(QString().setNum(augenzahl).toUtf8());
    socket->write("\n");
}

void Client::sendeZug(int zug) {

}
