#ifndef SPIELER_H
#define SPIELER_H
#include "zustand.h"
#include <QString>
#include <QObject>

class Spieler : public QObject
{
    Q_OBJECT
private:
    int anzStartfeld;
    int anzZielfeld;
    int anzGewurfelt;
    int augen;
    QString benutzerName;
    QString ip;
    bool awayFromKeyboard;
    bool darfKlicken;
    bool startpositionBelegt;
    bool zuendeGespielt;
    bool gueltigerZugVorhanden;
    void delay(int);
public:
    Zustand spielerFarbe;
    explicit Spieler(QObject *parent = 0);
    void wurfelPhase();
    void wurfelPhaseKI();
    void initSpieler(int i);
    bool getGueltigerZugVorhanden() {return gueltigerZugVorhanden;}
    void setGueltigerZugVorhanden(bool n) {gueltigerZugVorhanden=n;}
    bool getStartpositionBelegt() {return startpositionBelegt;}
    void setStartpositionBelegt(bool n) {startpositionBelegt=n;}
    bool getDarfKlicken() {return darfKlicken;}
    void setDarfKlicken(bool n) {darfKlicken=n;}
    void anzStartfeldVerringern() {anzStartfeld--;}
    void anzStartfeldErhoehen() {anzStartfeld++;}
    int getAnzStartfeld() {return anzStartfeld;}
    int getAnzZielfeld() {return anzZielfeld;}
    void anzZielfeldErhoehen() {anzZielfeld++;}
    int getAnzGewurfelt() {return anzGewurfelt;}
    void setAnzGewurfelt(int i) {anzGewurfelt=i;}
public slots:
    void spiele();
    void starteKI();
    void zugPhase(int);
//    void zugPhaseKI(int);
    void checkPhase();
    void checkPhaseKI();
    void setzeAugen(int);
signals:
    void spielerFertig();
    void darfWurfeln(bool);
    void wurfelKI();
    void figurBewegenKI();
    void wurfelFarbe(Zustand);
    void setLabelText(QString);
    void gewonnen();
};

#endif // SPIELER_H
