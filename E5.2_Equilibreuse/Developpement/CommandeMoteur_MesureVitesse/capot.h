#ifndef CAPOT_H
#define CAPOT_H

#include "mcculdaq.h"
#include <QTimer>
#include <QObject>

#define TEMPO_CAPOT 500

class Capot : public QObject
{
    Q_OBJECT
public:
    Capot(MccUldaq &_laCarte, const int _numDio, QObject *parent = nullptr);
private slots :
    void onTimerCapot_timeout();
signals:
    void EtatCapotChange(bool _etat);

private:
    MccUldaq &laCarte;
    bool etatCapot;
    int numDio;
    QTimer timerCapot;
};

#endif // CAPOT_H
