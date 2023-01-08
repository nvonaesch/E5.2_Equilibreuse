#ifndef REGLAGESM18_H
#define REGLAGESM18_H

#include <QWidget>
#include <QTimer>
#include "mcculdaq.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ReglageSM18; }
QT_END_NAMESPACE

class ReglageSM18 : public QWidget
{
    Q_OBJECT

public:
    ReglageSM18(QWidget *parent = nullptr);
    ~ReglageSM18();

private slots:
    void on_pushButtonLancerMesure_clicked();
    void onTimerMesure_timeout();
private:
    Ui::ReglageSM18 *ui;
    MccUldaq laCarte;
    QTimer timerMesure;
    double valeur;
};
#endif // REGLAGESM18_H
