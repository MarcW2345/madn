#include "timeout.h"


Timeout::Timeout(QObject *parent) :
    QObject(parent)
{
}

void Timeout::starte()
{
/*    int i=0;
    while(i<sekunden){
        timer();
        i++;
        std::cout << sekunden-i << std::endl;
        emit(sekundeVorbei(sekunden-i));
    }
    emit zeitAbgelaufen();*/
}

void Timeout::timer()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
