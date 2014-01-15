#include "mainwindow.h"
#include "ui_mainwindow.h"

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
                else if(zielfelder[next]->getZustand()==zustaende)
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
        else if(zielfelder[next]->getZustand()==zustaende)
            return false;
        else
            aktuell=next;
       }
    return true;
}

bool MainWindow::gueltigerZugVorhanden(int augen, Zustand spielerFarbe)
{
    Zustand aktuell;
    for (int j=1;j<41;j++)
    {
        aktuell=spielfeld[j]->getZustand();
        if (aktuell==spielerFarbe && gueltigerZug(j,aktuell,augen))
            return true;
    }
    for (int j=0;j<16;j++)
    {
        aktuell=zielfelder[j]->getZustand();
        if (aktuell==spielerFarbe && gueltigerZugZiel(j,aktuell,augen))
            return true;
    }
    return false;
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
        if(user[madn->getAnDerReihe()-1]->getDarfKlicken() && madn->getAnDerReihe()==spielfeld[aktuell]->getZustand()){
        if(gueltigerZug(aktuell,zustaende,augen) && startpositionGueltig(aktuell)){
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
                      for(int j=i+1;j<augen-1;j++)
                      {
                          next=zielfelder[aktuell]->getNext();
                          zielfelder[aktuell]->freistellen();
                          zielfelder[next]->feldBelegen(zustaende);
                          aktuell=next;
                               }
                      amZielAngelangt(madn->getAnDerReihe());
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
              user[(madn->getAnDerReihe())-1]->checkPhase();
          }
        else
            spielfeld[aktuell]->blinken();
        }
}


// Startfeld mit simpler Verkettung auf Startposition
void MainWindow::startfeldPressed(int next, int aktuell, Zustand zustaende){
    if(user[madn->getAnDerReihe()-1]->getDarfKlicken() && madn->getAnDerReihe()==startfelder[aktuell]->getZustand()){
        ui->textBrowser->append("ich habe Zugriff");
       if (ui->hauptwurfel->getAugen()==6)
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
          user[(madn->getAnDerReihe())-1]->anzStartfeldVerringern();
          user[(madn->getAnDerReihe())-1]->wurfelPhase();
       }
       else
       {
          startfelder[aktuell]->blinken();
          std::cout << "2 " << ui->hauptwurfel->getAugen() << user[madn->getAnDerReihe()-1]->getDarfKlicken() << madn->getAnDerReihe() << startfelder[aktuell]->getZustand() << std::endl;
       }
    }
}


// Funktion, wenn auf zielfeld geklick wird, da ja hier grundsätzlich anders gearbeitet wird
void MainWindow::zielfeldPressed(int next,int aktuell, Zustand zustaende){
    int augen=ui->hauptwurfel->getAugen();
        //hier muss selbstverstaendlich vor dem ausführen überprüft werden auf Gültigkeit des Zugs
    if(!(user[madn->getAnDerReihe()-1]->getStartpositionBelegt()) && user[madn->getAnDerReihe()-1]->getDarfKlicken() && madn->getAnDerReihe()==zielfelder[aktuell]->getZustand()){
    if(gueltigerZugZiel(aktuell,zustaende,augen)){
        for(int j=0;j<augen;j++)
        {
            next=zielfelder[aktuell]->getNext();
            zielfelder[aktuell]->freistellen();
            spielfeld[aktuell]->setalterZustand(nichtBelegt);
            zielfelder[next]->feldUeberspringen(zustaende);
            aktuell=next;
        }
        user[madn->getAnDerReihe()-1]->setDarfKlicken(false);
        amZielAngelangt(madn->getAnDerReihe());
        user[(madn->getAnDerReihe())-1]->checkPhase();
    }
    else
        zielfelder[aktuell]->blinken();
    }
}

void MainWindow::amZielAngelangt(Zustand n)
{
    int letztesZielfeld;
    int naechstesZielfeld;
    switch(n)
    {
    case gelb:letztesZielfeld=3; break;
    case grun:letztesZielfeld=7;break;
    case rot:letztesZielfeld=11;break;
    case blau:letztesZielfeld=15;break;
    case nichtBelegt:letztesZielfeld=99;break;
    }
    naechstesZielfeld=(letztesZielfeld-(user[madn->getAnDerReihe()-1]->getAnzZielfeld()));
    if (zielfelder[naechstesZielfeld]->getZustand()!=nichtBelegt)
        user[madn->getAnDerReihe()-1]->anzZielfeldErhoehen();
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

