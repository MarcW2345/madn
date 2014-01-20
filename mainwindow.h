#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "dialog.h"
#include "erstellen.h"
#include "feld.h"
#include "Netzwerkverbindung.h"
#include "spielfeld.h"
#include "startfeld.h"
#include "zielfeld.h"
#include "zustand.h"
#include "spiel.h"
#include "spieler.h"
#include "timeout.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void spielfelderInit();
    void zielfelderInit();
    void startfelderInit();
    void figurenInit(int,int);
    void spielInit(int,bool);
    void fressen(Zustand);
    bool gueltigerZug(int,Zustand,int);
    bool gueltigerZugZiel(int,Zustand,int);
    bool gueltigerZugVorhanden(int,Zustand);
    bool startpositionGueltig(int);
    void amZielAngelangt(Zustand);
    void wuerfelAnimation();
    void delayAnimation(int);
    void setzeBild(int,int);

private slots:
    void on_pushButton_clicked();
    void on_actionBeenden_triggered();
    void on_actionSpiel_beitreten_triggered();
    void on_actionSpiel_erstellen_triggered();
    void on_actionOptionen_triggered();

public slots:
    void settext();
    void wurfelPressed(int);
    void startfeldPressed(int,int,Zustand);
    void feldPressed(int,int,Zustand);
    void zielfeldPressed(int,int,Zustand);
    void spiele(Zustand);
    void zugPhase(int);
    void anderTimer(int);
    void empfangeSpielparamter(int,int,int,bool);
    void setzeNetzwerkverbindung(Netzwerkverbindung *verbindung);

private:
    Ui::MainWindow *ui;
    Dialog *d;
    Erstellen *e;
    Spielfeld* spielfeld[45];
    Startfeld* startfelder[16];
    Zielfeld* zielfelder[16];
    Spiel *madn=new Spiel();
    Spieler* user[4]={new Spieler(),new Spieler(),new Spieler(),new Spieler()};
    Timeout* timeout=new Timeout();
    QLabel* animationGelb[5],*animationGrun[5],*animationRot[5],*animationBlau[5];
    bool lokal;
    void delay(int);

signals:
    void nachrichtZuSenden(QString nachricht);
};

#endif // MAINWINDOW_H
