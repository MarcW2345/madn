#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "spielfeld.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    spielfelderInit();
    zielfelderInit();

    for(int i=1;i<41;i++){
        if(i==10 || i==20 || i==30 || i==40)
            connect(spielfeld[i], SIGNAL(verzweigungPressed(int,bool,Zustand)), this, SLOT(verzweigungsfeldPressed(int,bool,Zustand)));
        else
            connect(spielfeld[i], SIGNAL(mousePressed(int,Zustand)), this, SLOT(feldPressed(int,Zustand)));

        }
    // connect(ui->hauptwurfel, SIGNAL(wurfelPressed()), this, SLOT(wurfelPressed()));
}

MainWindow::~MainWindow()
{
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

void MainWindow::feldPressed(int next,Zustand zustaende){
    if(zustaende==nichtBelegt){
        ui->textBrowser->append(QString("Hier ist garnichts drauf, mein Freund!!"));
    }
    else if(zustaende!=nichtBelegt && next==0){

    }
    else{
    ui->textBrowser->append(QString("Naechstes Element: %1").arg(next));
    spielfeld[next]->feldBelegen(zustaende);
    }

}

void MainWindow::verzweigungsfeldPressed(int next,bool ziel, Zustand zustaende){
    //ui->textBrowser->append(QString("Naechstes Element: %1").arg(next));
    if(ziel)
    {
        if(zustaende==gelb)
            zielfelderGelb[0]->feldBelegen(zustaende);
        else if(zustaende==blau)
            zielfelderBlau[0]->feldBelegen(zustaende);
        else if(zustaende==rot)
            zielfelderRot[0]->feldBelegen(zustaende);
        else if(zustaende==grun)
            zielfelderGrun[0]->feldBelegen(zustaende);
         ui->textBrowser->append(QString("Im Ziel angekommen"));
    }
    else{
    ui->textBrowser->append(QString("Naechstes Element: %1").arg(next));
    spielfeld[next]->feldBelegen(zustaende);
    }

}
