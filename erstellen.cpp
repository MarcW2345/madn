#include "erstellen.h"
#include "ui_erstellen.h"

erstellen::erstellen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::erstellen)
{
    ui->setupUi(this);
}

erstellen::~erstellen()
{
    delete ui;
}
