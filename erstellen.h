#ifndef ERSTELLEN_H
#define ERSTELLEN_H

#include <QDialog>

namespace Ui {
class erstellen;
}

class erstellen : public QDialog
{
    Q_OBJECT

private:
    Ui::erstellen *ui;

public:
    explicit erstellen(QWidget *parent = 0);
    ~erstellen();
};

#endif // ERSTELLEN_H
