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
    ui->verzweigungsfeldgrun->setFarbe(grun);
    ui->verzweigungsfeldrot->setFarbe(rot);
    ui->verzweigungsfeldblau->setFarbe(blau);
    ui->verzweigungsfeldgelb->setFarbe(gelb);
    ui->verzweigungsfeldgrun->setZustand(grun);
    // Belegung von Spielfelder Testzweck

    spielfeld[11]->feldBelegen(rot);
}

void MainWindow::zielfelderInit()
{
    zielfelderBlau[0]=ui->zielfeldblau1;
    zielfelderBlau[1]=ui->zielfeldblau2;
    zielfelderBlau[2]=ui->zielfeldblau3;
    zielfelderBlau[3]=ui->zielfeldblau4;
    zielfelderGrun[0]=ui->zielfeldgrun1;
    zielfelderGrun[1]=ui->zielfeldgrun2;
    zielfelderGrun[2]=ui->zielfeldgrun3;
    zielfelderGrun[3]=ui->zielfeldgrun4;
    zielfelderRot[0]=ui->zielfeldrot1;
    zielfelderRot[1]=ui->zielfeldrot2;
    zielfelderRot[2]=ui->zielfeldrot3;
    zielfelderRot[3]=ui->zielfeldrot4;
    zielfelderGelb[0]=ui->zielfeldgelb1;
    zielfelderGelb[1]=ui->zielfeldgelb2;
    zielfelderGelb[2]=ui->zielfeldgelb3;
    zielfelderGelb[3]=ui->zielfeldgelb4;

}
