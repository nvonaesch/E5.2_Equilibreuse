#include "moteur.h"
#include <QDebug>

Moteur::Moteur(MccUldaq &_laCarte, const int _numCanal, const double _tensionMax, QObject *parent):
    QObject(parent),
    laCarte(_laCarte),
    numCanal(_numCanal),
    tensionMaxCommande(_tensionMax)
{
    UlError erreur;
    erreur = laCarte.ulAOut(numCanal,0);
    if(erreur != ERR_NO_ERROR)
        qDebug() << "Constructeur moteur Code erreur MccUldaq : " << erreur ;

    connect(&timerVitesse,&QTimer::timeout,this,&Moteur::onTimerVitesse_timeout);
}

Moteur::~Moteur()
{
    UlError erreur;
    erreur = laCarte.ulAOut(numCanal,0);
    if(erreur != ERR_NO_ERROR)
        qDebug() << "Destructeur moteur Code erreur MccUldaq : " << erreur ;
}

void Moteur::FixerConsigneVitesse(const int _pourcentage)
{
    vitesseConsigne=_pourcentage;
    decrementation=4;
    int pourcentageDivise=vitesseConsigne/decrementation;
    double valeurTension= (tensionMaxCommande * pourcentageDivise/ 100.0 );
    timerVitesse.start(1000);

    UlError erreur;
    erreur = laCarte.ulAOut(numCanal,valeurTension);
    if(erreur != ERR_NO_ERROR)
        qDebug() << "Fixer Consigne vitess Code erreur MccUldaq : " << erreur ;
}

void Moteur::onTimerVitesse_timeout()
{
    if(decrementation!=0){
        decrementation-=1;
        int pourcentageDivise=vitesseConsigne/decrementation;
        double valeurTension= (tensionMaxCommande * pourcentageDivise/ 100.0 );
        timerVitesse.start(1000);

        UlError erreur;
        erreur = laCarte.ulAOut(numCanal,valeurTension);
        if(erreur != ERR_NO_ERROR)
            qDebug() << "Fixer Consigne vitess Code erreur MccUldaq : " << erreur ;
    }
    else{
        timerVitesse.stop();
    }
}

