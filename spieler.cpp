#include "spieler.h"
#include "mainwindow.h"
#include "zustand.h"
#include <iostream>

Spieler::Spieler(QObject *parent) :
    QObject(parent)
{
}

void Spieler::wurfelPhase()
{
    if (anzStartfeld+anzZielfeld==4 && anzGewurfelt<3)
    {
        anzGewurfelt++;
        std::cout << "Bitte wuerfeln sie zum " << anzGewurfelt << ". mal.." << std::endl;
        emit darfWurfeln();
    }
    else
    {
        if (anzGewurfelt<1)
        {
            anzGewurfelt++;
            std::cout << "Bitte wuerfeln" << std::endl;
            emit darfWurfeln();
        }
        else
            checkPhase();
    }
}

void Spieler::initSpieler(int i)
{
    anzStartfeld=4;
    anzZielfeld=0;
    awayFromKeyboard=false;
    startpositionBelegt=false;
    zuendeGespielt=false;
    anzGewurfelt=0;
    switch (i)
    {
    case 0:spielerFarbe=gelb;break;
    case 1:spielerFarbe=blau;break;
    case 2:spielerFarbe=grun;break;
    case 3:spielerFarbe=rot;break;
    }
}

void Spieler::zugPhase(int n)
{
    augen=n;
    if (startpositionBelegt)
    {
        std::cout << "Bitte Startposition frei machen" << std::endl;
        darfKlicken=true;
    }
    else
    {
        if (anzStartfeld+anzZielfeld!=4)  //normales Szenario
        {
            std::cout << "Bitte Figur zum bewegen aussuchen" << std::endl;
            darfKlicken=true;
        }
        else
        {
            if (augen!=6 && anzGewurfelt<3)
            {
                std::cout << "Keine 6 gewuerfelt! Nochmal..." << std::endl;
                wurfelPhase();
            }
            else
            {
                if (augen==6)
                {
                    anzGewurfelt=0;
                    darfKlicken=true;
                    std::cout << "Bitte eine Figur von einem Startfeld auf die Startposition setzen" << std::endl;
                }
                else
                {
                    checkPhase();
                }
            }
        }
    }
}

void Spieler::checkPhase()
{
    if (anzZielfeld==4)
        zuendeGespielt=true;
    if (augen==6)
    {
        std::cout << "Sie haben eine 6 gewuerfelt und duerfen somit nochmal wuerfeln." << std::endl;
        anzGewurfelt=0;
        wurfelPhase();
    }
    else
    {
        std::cout << "Spieler ist fertig..." << std::endl;
        emit spielerFertig();
    }
}

void Spieler::spiele(Zustand n)
{
    spielerFarbe=n;
    emit wurfelFarbe(spielerFarbe);
    anzGewurfelt=0;
    wurfelPhase();
}

void Spieler::setzeAugen(int n)
{
    augen=n;
}
