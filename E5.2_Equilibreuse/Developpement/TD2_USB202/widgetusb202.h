#ifndef WIDGETUSB202_H
#define WIDGETUSB202_H

#include <QWidget>
#include <QTimer>
#include "mcculdaq.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetUSB202; }
QT_END_NAMESPACE

class WidgetUSB202 : public QWidget
{
    Q_OBJECT

public:
    WidgetUSB202(QWidget *parent = nullptr);
    ~WidgetUSB202();

    enum LED{
        LED1 = 4,
        LED2,
        LED3,
        LED4
    };

    enum BP{
        BP1 = 1,
        BP2 = 1 << 1,
        BP3 = 1 << 2,
        BP4 = 1 << 3
    };

private slots:
    void on_checkBox_LED1_stateChanged(int arg1);
    void on_checkBox_LED2_stateChanged(int arg1);
    void on_checkBox_LED3_stateChanged(int arg1);
    void on_checkBox_LED4_stateChanged(int arg1);
    void onTimerBP_timeOut();
private:
    Ui::WidgetUSB202 *ui;
    MccUldaq laCarte;
    QTimer leTimer;

};
#endif // WIDGETUSB202_H
