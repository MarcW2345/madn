#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "dialog.h"
#include "erstellen.h"
#include "feld.h"
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
    void fressen(Zustand);
    bool gueltigerZug(int,Zustand,int);
    bool gueltigerZugZiel(int,Zustand,int);
    bool startpositionGueltig(int);


private slots:
    void on_actionBeenden_triggered();
    void on_actionSpiel_beitreten_triggered();
    void on_actionSpiel_erstellen_triggered();

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

};

#endif // MAINWINDOW_H
