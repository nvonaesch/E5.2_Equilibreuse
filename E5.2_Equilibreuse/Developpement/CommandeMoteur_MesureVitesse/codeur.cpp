#include "codeur.h"
#include "constantes.h"
#include <QDebug>

Codeur::Codeur(MccUldaq &_laCarte, QObject *parent):
    QObject(parent),
    laCarte(_laCarte)
{
    connect(&timerVitesse,&QTimer::timeout,this,&Codeur::onTimerVitesse_timeout);
    timerVitesse.setTimerType(Qt::PreciseTimer);
    timerVitesse.setSingleShot(true);
}

Codeur::~Codeur()
{

}

void Codeur::LancerMesureVitesse()
{
    UlError erreur;
    erreur = laCarte.UlCClear();

    if (erreur !=0)
        qDebug() << "erreur Lancer Mesure Vitesse : " << erreur;

    timerVitesse.start(TEMPO_VITESSE);
}

void Codeur::ArreterMesureVitesse()
{
    timerVitesse.stop();
}

void Codeur::onTimerVitesse_timeout()
{
    UlError erreur;
    long valCpt;
    erreur = laCarte.ulCIn(valCpt);
    qDebug()<<"cpt :"<<valCpt;
    if (erreur != 0)
        qDebug() << "erreur Timer Vitesse timeout : " <<erreur;
    LancerMesureVitesse();

    int vitesseCalculee = ((valCpt/1000)*60);
    if(vitesse != vitesseCalculee){
        qDebug() <<"vitesse calculee :" <<vitesseCalculee;
        emit(VitesseChange(vitesseCalculee));
        vitesse = vitesseCalculee;
    }
}
