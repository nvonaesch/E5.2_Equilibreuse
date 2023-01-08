#ifndef CODEUR_H
#define CODEUR_H

#include "mcculdaq.h"
#include <QTimer>
#include <QObject>

class Codeur : public QObject
{
    Q_OBJECT
public:
    Codeur(MccUldaq &_laCarte, QObject *parent = nullptr);
    ~Codeur();
    void LancerMesureVitesse();
    void ArreterMesureVitesse();
public slots:
    void onTimerVitesse_timeout();
signals:
    void VitesseChange(int vitesse);
private:
    MccUldaq &laCarte;
    QTimer timerVitesse;
    int vitesse = 0;
};

#endif // CODEUR_H
