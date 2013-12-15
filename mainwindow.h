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

private slots:
    void on_actionBeenden_triggered();
    void on_actionSpiel_beitreten_triggered();
    void on_actionSpiel_erstellen_triggered();

public slots:
    void settext();
    void wurfelPressed(int);
    void feldPressed(int,Zustand);
    void verzweigungsfeldPressed(int,bool, Zustand);
private:
    Ui::MainWindow *ui;
    Dialog *d;
    erstellen *e;
    Spielfeld* spielfeld[45];
    Startfeld* startfelderGelb[4];
    Startfeld* startfelderGrun[4];
    Startfeld* startfelderRot[4];
    Startfeld* startfelderBlau[4];
    Zielfeld* zielfelderGelb[4];
    Zielfeld* zielfelderGrun[4];
    Zielfeld* zielfelderRot[4];
    Zielfeld* zielfelderBlau[4];

};

#endif // MAINWINDOW_H
