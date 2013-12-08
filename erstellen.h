#ifndef ERSTELLEN_H
#define ERSTELLEN_H

#include <QDialog>

namespace Ui {
class erstellen;
}

class erstellen : public QDialog
{
    Q_OBJECT

public:
    explicit erstellen(QWidget *parent = 0);
    ~erstellen();

private:
    Ui::erstellen *ui;
};

#endif // ERSTELLEN_H
