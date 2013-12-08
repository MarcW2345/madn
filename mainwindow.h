#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "dialog.h"
#include "erstellen.h"
#include "feld.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionBeenden_triggered();

    void on_actionSpiel_beitreten_triggered();

    void on_actionSpiel_erstellen_triggered();

public slots:
    void settext();
    void mousePressed(int);
    void wurfelPressed(int);

private:
    Ui::MainWindow *ui;
    Dialog *d;
    erstellen *e;
};

#endif // MAINWINDOW_H
