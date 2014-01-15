#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "spielfeld.h"
#include "wurfel.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setFixedSize(1250,800);
    spielfelderInit();
    zielfelderInit();
    startfelderInit();
    for(int i=0;i<4;i++)
        user[i]->initSpieler(i);
    // Spielfelder mit MouseEvents verknüpfen
    for(int i=1;i<41;i++){
            connect(spielfeld[i], SIGNAL(mousePressed(int,int, Zustand)), this, SLOT(feldPressed(int,int, Zustand)));
        }
    // Zielfelder mit Mouseevents verknuepfen
    for(int i=0;i<16;i++)
        connect(zielfelder[i], SIGNAL(mousePressed(int,int,Zustand)), this, SLOT(zielfeldPressed(int,int,Zustand)));
    // Startfelder mit Mouseevents verknuepfen
    for(int i=0;i<16;i++)
        connect(startfelder[i], SIGNAL(mousePressed(int,int,Zustand)), this, SLOT(startfeldPressed(int,int,Zustand)));
    // connect(ui->hauptwurfel, SIGNAL(wurfelPressed()), this, SLOT(wurfelPressed()));
    connect (madn, SIGNAL(spiele(Zustand)), this, SLOT(spiele(Zustand)));
    connect (ui->hauptwurfel, SIGNAL(zugPhase(int)), this, SLOT(zugPhase(int)));
    for (int i=0;i<4;i++)
    {
        connect (user[i], SIGNAL(wurfelFarbe(Zustand)),ui->hauptwurfel, SLOT(setzeFarbe(Zustand)));
        connect (user[i], SIGNAL(darfWurfeln()),ui->hauptwurfel, SLOT(darfWurfelnSlot()));
        connect (user[i], SIGNAL(spielerFertig()),madn, SLOT(naechster()));
        connect (user[i], SIGNAL(spielerFertig()),timeout, SLOT(starte()));
    }
    connect (timeout, SIGNAL(zeitAbgelaufen()),madn, SLOT(naechster()));
    connect (madn, SIGNAL(timerStart()),timeout, SLOT(starte()));

    connect (timeout, SIGNAL(sekundeVorbei(int)), this, SLOT(anderTimer(int)));
    lokal=true;
}

MainWindow::~MainWindow()
{
    delete timeout;
    delete ui;
}

void MainWindow::on_actionBeenden_triggered()
{
    this->close();
}
void MainWindow::settext()
{
    QString s= ui->lineEdit->text();
    ui->textBrowser->setText(s);
}

void MainWindow::on_actionSpiel_beitreten_triggered()
{
    this->d=new Dialog(this);
    d->show();
}

void MainWindow::on_actionSpiel_erstellen_triggered()
{
    this->e=new Erstellen(this);
    connect(e, SIGNAL(spielparameter(int,int,int,bool)),
            this, SLOT(empfangeSpielparamter(int,int,int,bool)));
    e->show();
}
void MainWindow::wurfelPressed(int i)
{
    ui->textBrowser->append(QString("wurfel %1").arg(i));
}

void MainWindow::spiele(Zustand n)
{
    user[n-1]->spiele(n);
}
void MainWindow::zugPhase(int n)
{
    bool kannSpielen=gueltigerZugVorhanden(n,madn->getAnDerReihe());
    user[(madn->getAnDerReihe())-1]->setGueltigerZugVorhanden(kannSpielen);
    user[(madn->getAnDerReihe())-1]->zugPhase(n);
}

void MainWindow::anderTimer(int n)
{
    ui->timer->display(n);
}

void MainWindow::empfangeSpielparamter(int timer, int anzSpieler,
                                       int figurArt, bool lokalesSpiel)
{
    figurenInit(anzSpieler,figurArt);
    timeout->setSekunden(timer);
    spielInit(anzSpieler,lokalesSpiel);
    if (lokalesSpiel)
        spiele(gelb);
    else
    {

    }
    /*Spielparameter:
     timer in sekunden
     anzSpieler: 2,3 oder 4;
     spielfiguren: 1=standardfiguren, 2=schneemann, 3=smiley
     lokalesspiel: 0=nein, 1=ja
    */
}

