#include "spieler.h"
#include "mainwindow.h"
#include "zustand.h"
#include <iostream>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>

Spieler::Spieler(QObject *parent) :
    QObject(parent)
{
}

/**Initialisiert die Variablen von Spieler für den Start einer Partie. Funktion
  *ist nötig, da bei einem zweiten Spiel nicht nochmal der Konstrukor aufgerufen
  *wird und so die Variablen zu Anfang des zweiten Spiels "falsche" Werte hätten*/
void Spieler::initSpieler(int i)
{
    anzStartfeld=4;
    anzZielfeld=0;
    awayFromKeyboard=false;
    startpositionBelegt=false;
    zuendeGespielt=false;
    gueltigerZugVorhanden=false;
    darfKlicken=false;
    anzGewurfelt=0;
    switch (i)
    {
    case 0:spielerFarbe=gelb;break;
    case 1:spielerFarbe=grun;break;
    case 2:spielerFarbe=rot;break;
    case 3:spielerFarbe=blau;break;
    }
}

/**Setzt die Würfelfarbe und lässt den Spieler spielen*/
void Spieler::spiele()
{
    emit wurfelFarbe(spielerFarbe);
    anzGewurfelt=0;
    wurfelPhase();
}

void Spieler::starteKI()
{
    emit darfWurfeln(false);
    anzGewurfelt=0;
    wurfelPhaseKI();
}

/**Überprüft ob der Spieler würfel darf*/
void Spieler::wurfelPhase()
{
    /**Sofern alle eigenen Spielfiguren auf den Startfeldern stehen
      *und/oder am Ende angekommen sind, darf man 3 mal würfeln*/
    if (anzStartfeld+anzZielfeld==4 && anzGewurfelt<3)
    {
        anzGewurfelt++;
        emit setLabelText(QString("Bitte wuerfeln sie zum %1. mal").arg(anzGewurfelt));
        emit darfWurfeln(true);
    }
    else
    {
        /**Hat man eine Figur auf dem Spielbrett, die man bewegen kann und
          *die nicht auf den Startfeldern steht, darf man nur einmal würfeln*/
        if (anzGewurfelt<1)
        {
            anzGewurfelt++;
            emit setLabelText(QString("Bitte wuerfeln"));
            emit darfWurfeln(true);
        }
        else
            checkPhase();
    }
}

/**Überprüft ob der Spieler würfel darf*/
void Spieler::wurfelPhaseKI()
{
    /**Sofern alle eigenen Spielfiguren auf den Startfeldern stehen
      *und/oder am Ende angekommen sind, darf man 3 mal würfeln*/
    if (anzStartfeld+anzZielfeld==4 && anzGewurfelt<3)
    {
        anzGewurfelt++;
        emit setLabelText(QString("Es wird zum %1. mal gewuerfelt.").arg(anzGewurfelt));
        emit wurfelKI();
    }
    else
    {
        /**Hat man eine Figur auf dem Spielbrett, die man bewegen kann und
          *die nicht auf den Startfeldern steht, darf man nur einmal würfeln*/
        if (anzGewurfelt<1)
        {
            anzGewurfelt++;
            emit setLabelText(QString("Es wird gewuerfelt"));
            emit wurfelKI();
        }
        else
            checkPhaseKI();
    }
}

/**Nach erfolgreicher Würfelphase und ermittelter Augenzahl, geht es in
  *die Zugphase. Hier wird entschieden welche Figur/-en man bewegen darf/muss
  *und dies per Textausgabe mitgeteilt*/
void Spieler::zugPhase(int n)
{
    augen=n;
    /**Die Regeln besagen: Sofern die Startposition belegt ist, muss man diese "frei"
      *machen. Es sei denn eine eigene Figur verhindert das(Man hat eine Zahl gewürfelt
      *mit der man sich selbst schmeissen würde, was den Regeln nach aber nicht erlaubt ist).
      *Dies wird hier überprüft*/
    if (startpositionBelegt)
    {
        emit setLabelText(QString("Bitte Startposition frei machen"));
        darfKlicken=true;
    }
    else
    {
        /**Wenn eine Figur außerhalb der Startfeldern ist und man sie theoretisch bewegen kann,
          *geht es hier weiter(im weiteren Verlauf "normales Szenario" genannt).*/
        if (anzStartfeld+anzZielfeld!=4)
        {
            /**Hier wird geprüft, ob man mit der ermittelten Augenzahl überhaupt einen Zug
              *beim normalen Szenario machen kann. Ansonsten wird gepasst.*/
            if (gueltigerZugVorhanden)
            {
                emit setLabelText(QString("Bitte Figur zum bewegen aussuchen"));
                darfKlicken=true;
            }
            else
            {
                emit setLabelText(QString("Sie können keine Figur bewegen und müssen somit passen."));
                delay(2000);
                checkPhase();
            }
        }
        else
        {
            /**Ist keine Figur auf der Startposition, kein normales Szenario vorhanden, hat man
              *noch nicht 3 mal gewürfelt und beim letzten würfeln keine 6 bekommen , darf
              *man nochmal würfeln. Dies wird hier überprüft. */
            if (augen!=6 && anzGewurfelt<3)
            {
                emit setLabelText(QString("Keine 6 gewuerfelt! Nochmal..."));
                wurfelPhase();
            }
            else
            {
                /**Hat man eine 6 gewürfelt, ist keine Figur auf der Startposition und kein
                  *normales Szenario vorhanden, muss man eine Figur auf die Startposition gesetzt*/
                if (augen==6)
                {
                    anzGewurfelt=0;
                    darfKlicken=true;
                    emit setLabelText(QString("Bitte eine Figur von einem Startfeld auf die Startposition setzen"));
                }
                /**Trifft alles nicht zu, geht es in die Checkphase*/
                else
                {
                    checkPhase();
                }
            }
        }
    }
}

/*void Spieler::zugPhaseKI(int n)
{
    augen=n;
      *Die Regeln besagen: Sofern die Startposition belegt ist, muss man diese "frei"
      *machen. Es sei denn eine eigene Figur verhindert das(Man hat eine Zahl gewürfelt
      *mit der man sich selbst schmeissen würde, was den Regeln nach aber nicht erlaubt ist).
      *Dies wird hier überprüft
    if (startpositionBelegt)
    {
        emit setLabelText(QString("Startposition wird versucht frei zu mache.n"));
        emit figurBewegenKI();
    }
    else
    {
          *Wenn eine Figur außerhalb der Startfeldern ist und man sie theoretisch bewegen kann,
          *geht es hier weiter(im weiteren Verlauf "normales Szenario" genannt).
        if (anzStartfeld+anzZielfeld!=4)
        {
              *Hier wird geprüft, ob man mit der ermittelten Augenzahl überhaupt einen Zug
              *beim normalen Szenario machen kann. Ansonsten wird gepasst.
            if (gueltigerZugVorhanden)
            {
                emit setLabelText(QString("Figur wird bewegt."));
                emit figurBewegenKI();
            }
            else
            {
                emit setLabelText(QString("Es gibt leider keinen moeglichen Zug."));
                delay(2000);
                checkPhaseKI();
            }
        }
        else
        {
              *Ist keine Figur auf der Startposition, kein normales Szenario vorhanden, hat man
              *noch nicht 3 mal gewürfelt und beim letzten würfeln keine 6 bekommen , darf
              *man nochmal würfeln. Dies wird hier überprüft.
            if (augen!=6 && anzGewurfelt<3)
            {
                emit setLabelText(QString("Keine 6 gewuerfelt! Nochmal..."));
                wurfelPhaseKI();
            }
            else
            {
                  *Hat man eine 6 gewürfelt, ist keine Figur auf der Startposition und kein
                  *normales Szenario vorhanden, muss man eine Figur auf die Startposition gesetzt
                if (augen==6)
                {
                    anzGewurfelt=0;
                    emit setLabelText(QString("Eine Figur wird von einem Startfeld auf die Startposition gesetzt."));
                    emit figurBewegenKI();
                }
                  *Trifft alles nicht zu, geht es in die Checkphase
                else
                {
                    checkPhaseKI();
                }
            }
        }
    }
}*/

/**Es wird überprüft ob die Siegbedingung erfüllt ist und/oder ob man eine 6 gewürfelt hat.
  *Hat man die Siegbedingung erfüllt, ist man natürlich der Sieger und das Spiel ist vorbei.
  *Hat man eine 6 gewürfelt, darf man nochmal würfeln und somit geht es wieder in die Würfelphase.
  *Trifft beides nicht zu, ist der nächste Spieler an der Reihe*/
void Spieler::checkPhase()
{
    if (anzZielfeld==4)
    {
        emit gewonnen();
        zuendeGespielt=true;
    }
    else
    {
        if (augen==6)
        {
           emit setLabelText(QString("Sie haben eine 6 gewuerfelt und duerfen somit nochmal wuerfeln."));
           anzGewurfelt=0;
           wurfelPhase();
        }
        else
        {
            emit setLabelText(QString("Spieler ist fertig..."));
            emit spielerFertig();
        }
    }
}

void Spieler::checkPhaseKI()
{
    if (anzZielfeld==4)
    {
        delay(2000);
        emit gewonnen();
    }
    else
    {
        if (augen==6)
        {
           emit setLabelText(QString("Sie haben eine 6 gewuerfelt und duerfen somit nochmal wuerfeln."));
           anzGewurfelt=0;
           delay(2000);
           wurfelPhaseKI();
        }
        else
        {
            emit setLabelText(QString("Spieler ist fertig..."));
            delay(2000);
            emit spielerFertig();
        }
    }
}

void Spieler::setzeAugen(int n)
{
    augen=n;
}

void Spieler::delay(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
