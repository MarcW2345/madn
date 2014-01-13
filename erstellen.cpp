#include "erstellen.h"
#include "ui_erstellen.h"

Erstellen::Erstellen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Erstellen)
{
    ui->setupUi(this);
    figuren << "Standardfigur" << "Schneemann" << "Smiley";
    spieler << "2 Spieler" << "3 Spieler" << "4 Spieler";

    ui->cbSpielfiguren->insertItems(1,figuren);
    ui->cbSpieler->insertItems(1,spieler);

    connect(ui->sbTimeout , SIGNAL(valueChanged(int)),
                this, SLOT(settimer(int)));
    connect(ui->cbLokal , SIGNAL(stateChanged(int)),
                this, SLOT(setlokalesSpiel(int)));
    connect(ui->cbSpielfiguren, SIGNAL(activated(int)),
                this, SLOT(setspielfiguren(int)));
    connect(ui->cbSpieler, SIGNAL(activated(int)),
                this, SLOT(setanzSpieler(int)));

    connect(ui->btnAbbrechen, SIGNAL(clicked()),
                this, SLOT(abbrechen()));
    connect(ui->btnBestatigen, SIGNAL(clicked()),
            this, SLOT(bestaetigen()));
}

void Erstellen::settimer(int n){
    timer = n;
}
void Erstellen::setlokalesSpiel(int n){
    if(n){
        lokalesSpiel=true;
    }
    else
        lokalesSpiel=false;
}

void Erstellen::setanzSpieler(int n)
{
    anzSpieler=n+2;
}

void Erstellen::setspielfiguren(int n)
{
    spielfiguren=n+1;
}

void Erstellen::abbrechen(){
    timer=60;
    lokalesSpiel=false;
    anzSpieler=2;
    spielfiguren=1;
    this->close();
}


void Erstellen::bestaetigen()
{
    emit spielparameter(timer,anzSpieler,spielfiguren,lokalesSpiel);
    this->close();
}

Erstellen::~Erstellen()
{
    delete ui;
}
