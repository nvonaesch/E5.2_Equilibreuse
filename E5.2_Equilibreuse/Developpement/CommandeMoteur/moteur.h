#ifndef MOTEUR_H
#define MOTEUR_H

#include "mcculdaq.h"
#include <QObject>
#include <QTimer>

class Moteur : public QObject
{
    Q_OBJECT
public:
    Moteur(MccUldaq &_laCarte, const int _numCanal, const double _tensionMax=4, QObject *parent = nullptr);
    ~Moteur();
    void FixerConsigneVitesse(const int _pourcentage);
private slots:
    void onTimerVitesse_timeout();
private:
    MccUldaq &laCarte;
    int numCanal;
    double tensionMaxCommande;
    QTimer timerVitesse;
    double vitesseConsigne;
    int decrementation;
};



#endif // MOTEUR_H
