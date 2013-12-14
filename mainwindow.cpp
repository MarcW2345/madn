#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   /* connect(ui->startfeld11, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld11, SIGNAL(mousePressed(int)), ui->startfeld11, SLOT(change()));
    connect(ui->startfeld11, SIGNAL(mousePressed(int)), ui->startposgrun, SLOT(belegen()));
    connect(ui->startfeld12, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld13, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld14, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld21, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld22, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld23, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld24, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld31, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld32, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld33, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld34, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld41, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld42, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld43, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));
    connect(ui->startfeld44, SIGNAL(mousePressed(int)), this, SLOT(mousePressed(int)));*/

    connect(ui->hauptwurfel, SIGNAL(wurfelPressed(int)), this, SLOT(wurfelPressed(int)));
// Feldtyp setzen , welche Farbe
    /*ui->startfeld11->setFeldtyp(1);
    ui->startfeld13->setFeldtyp(1);
    ui->startfeld14->setFeldtyp(1);
    ui->startfeld21->setFeldtyp(2);
    ui->startfeld22->setFeldtyp(2);
    ui->startfeld23->setFeldtyp(2);
    ui->startfeld24->setFeldtyp(2);
    ui->startfeld31->setFeldtyp(3);
    ui->startfeld32->setFeldtyp(3);
    ui->startfeld33->setFeldtyp(3);
    ui->startfeld34->setFeldtyp(3);
    ui->startfeld41->setFeldtyp(4);
    ui->startfeld42->setFeldtyp(4);
    ui->startfeld43->setFeldtyp(4);
    ui->startfeld44->setFeldtyp(4);*/

   // feldl* felder[3];
   // felder[0]=ui->startposgrun;
   // felder[1]=ui->feld01;
   // felder[2]=ui->feld02;

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

void MainWindow::mousePressed(int i)
{
    ui->textBrowser->append(QString("Mouse pressed in Feldtyp %1").arg(i));
}

void MainWindow::wurfelPressed(int i)
{
    ui->textBrowser->append(QString("wurfel %1").arg(i));
}
