#include "reglagesm18.h"
#include "ui_reglagesm18.h"


ReglageSM18::ReglageSM18(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReglageSM18)
{
    ui->setupUi(this);

    connect(&timerMesure,&QTimer::timeout,this,&ReglageSM18::onTimerMesure_timeout);
}

ReglageSM18::~ReglageSM18()
{
    delete ui;
}

void ReglageSM18::on_pushButtonLancerMesure_clicked()
{

    if(ui->pushButtonLancerMesure->text() == "Arrêter Mesure"){
        ui->pushButtonLancerMesure->setText("Lancer Mesure");
        timerMesure.stop();
    } else {
        ui->pushButtonLancerMesure->setText("Arrêter Mesure");
        timerMesure.start(500);
    }
}

void ReglageSM18::onTimerMesure_timeout()
{
    laCarte.ulAIn(0, valeur);
    ui->lcdNumber->display(valeur);
}


