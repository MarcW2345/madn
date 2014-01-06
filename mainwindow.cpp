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
    spielfelderInit();
    zielfelderInit();
    startfelderInit();
    madn->initSpiel();
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
    connect (ui->pushButton, SIGNAL(clicked()), madn, SLOT(starteSpiel()));
    connect (madn, SIGNAL(timerStart()),timeout, SLOT(starte()));


    //connect (ui->pushButton, SIGNAL(clicked()), timeout, SLOT(starte()));
    connect (timeout, SIGNAL(sekundeVorbei(int)), this, SLOT(anderTimer(int)));
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
    this->e=new erstellen(this);
    e->show();
}
void MainWindow::wurfelPressed(int i)
{
    ui->textBrowser->append(QString("wurfel %1").arg(i));
}


// Überprüft Gültigkeit für den Klick auf einem Spielfeld
bool MainWindow::gueltigerZug(int aktuell, Zustand zustaende,int augen){
    for(int i=0;i<augen;i++)
    {
        int next=spielfeld[aktuell]->getNext();
        // Für den Fall, dass im selben Zug in Zielfelder gelaufen wird
        if(next==0){
            next=spielfeld[aktuell]->getnextZielposition();
            aktuell=next;
            for(int j=i+1;j<augen;j++)
               {
                next=zielfelder[aktuell]->getNext();
                if(next==0)
                    return false;
                else if(j==augen-1 && zielfelder[next]->getZustand()==zustaende)
                    return false;
                else
                    aktuell=next;
               }
            break;
        }
        // Für den Fall, dass ganz normal im Spielfeld weitergelaufen wird
        else{
                if(i==augen-1 && spielfeld[next]->getZustand()==zustaende)
                    return false;
                aktuell=next;
            }
    }
    return true;
}
bool MainWindow::gueltigerZugZiel(int aktuell,Zustand zustaende, int augen){
    for(int i=0;i<augen;i++)
       {
        int next=zielfelder[aktuell]->getNext();
        if(next==0)
            return false;
        else if(i==augen-1 && zielfelder[next]->getZustand()==zustaende)
            return false;
        else
            aktuell=next;
       }
    return true;

}

void MainWindow::fressen(Zustand Farbe){
    int i;
    std::cout << Farbe << " " << user[0]->spielerFarbe << " " << user[1]->spielerFarbe << " " << user[2]->spielerFarbe << " " << user[3]->spielerFarbe << " " << std::endl;
    if(Farbe==gelb){
        for(i=0;i<4;i++){
            if(startfelder[i]->getZustand()==nichtBelegt){
                startfelder[i]->feldBelegen(Farbe);
                user[Farbe-1]->anzStartfeldErhoehen();
                break;
            }
        }
            startfelder[i]->feldBelegen(Farbe);}
    else if(Farbe==grun){
        for(i=4;i<8;i++){
            if(startfelder[i]->getZustand()==nichtBelegt){
                startfelder[i]->feldBelegen(Farbe);
                user[Farbe-1]->anzStartfeldErhoehen();
                break;
            }
        }
            startfelder[i]->feldBelegen(Farbe);}
    else if(Farbe==rot){
        for(i=8;i<12;i++){
            if(startfelder[i]->getZustand()==nichtBelegt){
                startfelder[i]->feldBelegen(Farbe);
                user[Farbe-1]->anzStartfeldErhoehen();
                break;
            }
        }
            startfelder[i]->feldBelegen(Farbe);}
    else if(Farbe==blau){
        for(i=12;i<15;i++){
            if(startfelder[i]->getZustand()==nichtBelegt){
                startfelder[i]->feldBelegen(Farbe);
                user[Farbe-1]->anzStartfeldErhoehen();
                break;
            }
        }
}
}

bool MainWindow::startpositionGueltig(int aktuell)
{
    int i;
    switch (madn->getAnDerReihe())
    {
    case gelb: i=1;break;
    case grun: i=11;break;
    case rot: i=21;break;
    case blau: i=31;break;
    case nichtBelegt: i=0;break;
    }
    if (user[madn->getAnDerReihe()-1]->getStartpositionBelegt() && user[madn->getAnDerReihe()-1]->getDarfKlicken())
    {
        std::cout << "1 bestanden" << std::endl;
        if (i==aktuell)
        {
            user[madn->getAnDerReihe()-1]->setStartpositionBelegt(false);
            std::cout << "Startposition wird frei gemacht" << std::endl;
            return true;
        }
        else

            std::cout << "tut  " << i << madn->getAnDerReihe() << aktuell << std::endl;
            return false;
    }
    else
        return true;

}

void MainWindow::feldPressed(int next,int aktuell, Zustand zustaende){
        int augen=ui->hauptwurfel->getAugen();
        // Abfrage bevor durchlaufen wird nach Gültigkeit des Spielzuges
        if(gueltigerZug(aktuell,zustaende,augen) && startpositionGueltig(aktuell) && user[madn->getAnDerReihe()-1]->getDarfKlicken() && madn->getAnDerReihe()==spielfeld[aktuell]->getZustand()){
            int augen=ui->hauptwurfel->getAugen();
              for(int i=0;i<augen;i++)
              {
                  next=spielfeld[aktuell]->getNext();
                  if(next==0){
                      next=spielfeld[aktuell]->getnextZielposition();
                      spielfeld[aktuell]->freistellen();
                      spielfeld[aktuell]->setalterZustand(nichtBelegt);
                      zielfelder[next]->feldUeberspringen(zustaende);
                      aktuell=next;
                      // nach Verzweigungsfeld wird ja noch auf Zielfelder gelaufen( restlichen Bewegungen)
                      for(int j=i;j<augen-1;j++)
                      {
                          next=zielfelder[aktuell]->getNext();
                          zielfelder[aktuell]->freistellen();
                          zielfelder[next]->feldBelegen(zustaende);
                          aktuell=next;
                               }
                      // Break da Zielfelder den Rest der Bewegungen verbraucht hat
                      break;
                  }
                  // Für den normalen Fall, in dem ganz normal weiter gelaufen wird
                  else{
                      spielfeld[aktuell]->freistellen();
                      spielfeld[aktuell]->setalterZustand(nichtBelegt);
                      if(i<augen-1)
                       spielfeld[next]->feldUeberspringen(zustaende);
                      else{
                          Zustand Farbe=spielfeld[next]->getZustand();
                          spielfeld[next]->feldBelegen(zustaende);
                          if(Farbe!=nichtBelegt)
                              fressen(Farbe);
                          }
                          aktuell=next;
                          ui->textBrowser->append(QString("Naechstes Element: %1").arg(next));
                  }
              }
              user[madn->getAnDerReihe()-1]->setDarfKlicken(false);
              user[(madn->getAnDerReihe())-1]->wurfelPhase();
          }
        else
            ui->textBrowser->append(QString("Kein gueltiger Zug!!"));
}

// Startfeld mit simpler Verkettung auf Startposition
void MainWindow::startfeldPressed(int next, int aktuell, Zustand zustaende){
    if (ui->hauptwurfel->getAugen()==6 && user[madn->getAnDerReihe()-1]->getDarfKlicken() && madn->getAnDerReihe()==startfelder[aktuell]->getZustand())
    {
        std::cout << "1" << std::endl;
        ui->textBrowser->append(QString("Naechstes Element: %1").arg(next));
        startfelder[aktuell]->freistellen();
        Zustand Farbe=spielfeld[next]->getZustand();
        spielfeld[next]->feldBelegen(zustaende);
        if(Farbe!=nichtBelegt)
            fressen(Farbe);
        user[madn->getAnDerReihe()-1]->setDarfKlicken(false);
        user[madn->getAnDerReihe()-1]->setStartpositionBelegt(true);
        user[(madn->getAnDerReihe())-1]->wurfelPhase();
        user[(madn->getAnDerReihe())-1]->anzStartfeldVerringern();
    }
    else

        std::cout << "2 " << ui->hauptwurfel->getAugen() << user[madn->getAnDerReihe()-1]->getDarfKlicken() << madn->getAnDerReihe() << startfelder[aktuell]->getZustand() << std::endl;
}

// Funktion, wenn auf zielfeld geklick wird, da ja hier grundsätzlich anders gearbeitet wird
void MainWindow::zielfeldPressed(int next,int aktuell, Zustand zustaende){
    int augen=ui->hauptwurfel->getAugen();
        //hier muss selbstverstaendlich vor dem ausführen überprüft werden auf Gültigkeit des Zugs
    if(gueltigerZugZiel(aktuell,zustaende,augen) && !(user[madn->getAnDerReihe()-1]->getStartpositionBelegt()) && user[madn->getAnDerReihe()-1]->getDarfKlicken() && madn->getAnDerReihe()==spielfeld[aktuell]->getZustand()){
        for(int j=0;j<augen;j++)
        {
            next=zielfelder[aktuell]->getNext();
            zielfelder[aktuell]->freistellen();
            spielfeld[aktuell]->setalterZustand(nichtBelegt);
            zielfelder[next]->feldUeberspringen(zustaende);
            aktuell=next;
        }
        user[madn->getAnDerReihe()-1]->setDarfKlicken(false);
    }
    else
        ui->textBrowser->append(QString("Kein gueltiger Zug!!"));
    }

void MainWindow::spiele(Zustand n)
{
    user[n-1]->spiele(n);
}
void MainWindow::zugPhase(int n)
{
    user[(madn->getAnDerReihe())-1]->zugPhase(n);
}

void MainWindow::anderTimer(int n)
{
    ui->timer->display(n);
}

