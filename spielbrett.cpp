#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::spielfelderInit()
{
    spielfeld[1]=ui->startposgelb;
    spielfeld[2]=ui->feld02;
    spielfeld[3]=ui->feld03;
    spielfeld[4]=ui->feld04;
    spielfeld[5]=ui->feld05;
    spielfeld[6]=ui->feld06;
    spielfeld[7]=ui->feld07;
    spielfeld[8]=ui->feld08;
    spielfeld[9]=ui->feld09;
    spielfeld[10]=ui->verzweigungsfeldgrun;
    spielfeld[11]=ui->startposgrun;
    spielfeld[12]=ui->feld12;
    spielfeld[13]=ui->feld13;
    spielfeld[14]=ui->feld14;
    spielfeld[15]=ui->feld15;
    spielfeld[16]=ui->feld16;
    spielfeld[17]=ui->feld17;
    spielfeld[18]=ui->feld18;
    spielfeld[19]=ui->feld19;
    spielfeld[20]=ui->verzweigungsfeldrot;
    spielfeld[21]=ui->startposrot;
    spielfeld[22]=ui->feld22;
    spielfeld[23]=ui->feld23;
    spielfeld[24]=ui->feld24;
    spielfeld[25]=ui->feld25;
    spielfeld[26]=ui->feld26;
    spielfeld[27]=ui->feld27;
    spielfeld[28]=ui->feld28;
    spielfeld[29]=ui->feld29;
    spielfeld[30]=ui->verzweigungsfeldblau;
    spielfeld[31]=ui->startposblau;
    spielfeld[32]=ui->feld32;
    spielfeld[33]=ui->feld33;
    spielfeld[34]=ui->feld34;
    spielfeld[35]=ui->feld35;
    spielfeld[36]=ui->feld36;
    spielfeld[37]=ui->feld37;
    spielfeld[38]=ui->feld38;
    spielfeld[39]=ui->feld39;
    spielfeld[40]=ui->verzweigungsfeldgelb;

    for(int i=1;i<41;i++)
        spielfeld[i]->setSpielfeldNr(i);
    for(int i=1;i<40;i++)
       spielfeld[i]->setNext(i+1);
    spielfeld[40]->setNext(1);
    for(int i=1;i<40;i++)
       spielfeld[i]->setZustand(nichtBelegt);
    for(int i=1;i<=40;i++)
       spielfeld[i]->setfeldNr(i);
// Belegung Farbe und next Feldeintrag bei den Zielfeldern für Verzweigungsfelder
    ui->verzweigungsfeldgrun->setFarbe(grun);
    ui->verzweigungsfeldgrun->setnextZielposition(4);
    ui->verzweigungsfeldrot->setFarbe(rot);
    ui->verzweigungsfeldrot->setnextZielposition(8);
    ui->verzweigungsfeldblau->setFarbe(blau);
    ui->verzweigungsfeldblau->setnextZielposition(12);
    ui->verzweigungsfeldgelb->setFarbe(gelb);
    ui->verzweigungsfeldgelb->setnextZielposition(0);


}

void MainWindow::zielfelderInit()
{
    zielfelder[0]=ui->zielfeldgelb1;
    zielfelder[1]=ui->zielfeldgelb2;
    zielfelder[2]=ui->zielfeldgelb3;
    zielfelder[3]=ui->zielfeldgelb4;
    zielfelder[4]=ui->zielfeldgrun1;
    zielfelder[5]=ui->zielfeldgrun2;
    zielfelder[6]=ui->zielfeldgrun3;
    zielfelder[7]=ui->zielfeldgrun4;
    zielfelder[8]=ui->zielfeldrot1;
    zielfelder[9]=ui->zielfeldrot2;
    zielfelder[10]=ui->zielfeldrot3;
    zielfelder[11]=ui->zielfeldrot4;
    zielfelder[12]=ui->zielfeldblau1;
    zielfelder[13]=ui->zielfeldblau2;
    zielfelder[14]=ui->zielfeldblau3;
    zielfelder[15]=ui->zielfeldblau4;

    for(int i=0;i<3;i++)
        zielfelder[i]->setNext(i+1);
    for(int i=4;i<7;i++)
        zielfelder[i]->setNext(i+1);
    for(int i=8;i<11;i++)
        zielfelder[i]->setNext(i+1);
    for(int i=12;i<15;i++)
        zielfelder[i]->setNext(i+1);
    // Die letzten 4 Zielfelder aller Farben zeigen auf NULL -> ENDE , leider hier nur '0'
    zielfelder[3]->setNext(0);
    zielfelder[7]->setNext(0);
    zielfelder[11]->setNext(0);
    zielfelder[15]->setNext(0);
    for(int i=0;i<16;i++){
        zielfelder[i]->setfeldNr(i);
        zielfelder[i]->setZustand(nichtBelegt);
    }
}

void MainWindow::startfelderInit(){
    startfelder[0]=ui->startfeldgelb1;
    startfelder[1]=ui->startfeldgelb2;
    startfelder[2]=ui->startfeldgelb3;
    startfelder[3]=ui->startfeldgelb4;
    startfelder[4]=ui->startfeldgrun1;
    startfelder[5]=ui->startfeldgrun2;
    startfelder[6]=ui->startfeldgrun3;
    startfelder[7]=ui->startfeldgrun4;
    startfelder[8]=ui->startfeldrot1;
    startfelder[9]=ui->startfeldrot2;
    startfelder[10]=ui->startfeldrot3;
    startfelder[11]=ui->startfeldrot4;
    startfelder[12]=ui->startfeldblau1;
    startfelder[13]=ui->startfeldblau2;
    startfelder[14]=ui->startfeldblau3;
    startfelder[15]=ui->startfeldblau4;
    for(int i=0;i<16;i++){
        startfelder[i]->setZustand(nichtBelegt);
    }
    for(int i=0;i<4;i++){
        startfelder[i]->setfeldNr(i);
        startfelder[i]->setNext(1);
        startfelder[i]->feldBelegen(gelb);
    }
    for(int i=4;i<8;i++){
        startfelder[i]->setfeldNr(i);
        startfelder[i]->setNext(11);
        startfelder[i]->feldBelegen(grun);
    }
    for(int i=8;i<12;i++){
        startfelder[i]->setfeldNr(i);
        startfelder[i]->setNext(21);
        startfelder[i]->feldBelegen(rot);
    }
    for(int i=12;i<16;i++){
        startfelder[i]->setfeldNr(i);
        startfelder[i]->setNext(31);
        startfelder[i]->feldBelegen(blau);
    }

}

