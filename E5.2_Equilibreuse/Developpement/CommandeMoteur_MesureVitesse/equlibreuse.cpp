#include "equlibreuse.h"
#include "ui_equlibreuse.h"

Equlibreuse::Equlibreuse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Equlibreuse)
{
    ui->setupUi(this);
    leCapot = new Capot(laCarte,0,this);
    leMoteur = new Moteur(laCarte,0,3);
    leCodeur = new Codeur(laCarte,this);
    connect(leCapot,&Capot::EtatCapotChange,this,&Equlibreuse::onCapot_EtatCapotChange);

    ui->statusbar->addPermanentWidget(&labelEtatCapot);

    connect(leCodeur,&Codeur::VitesseChange,this,&Equlibreuse::onCodeur_NouvelleVitesse);

}

Equlibreuse::~Equlibreuse()
{
    delete ui;
    delete leCapot;
    delete leMoteur;
}

void Equlibreuse::onCapot_EtatCapotChange(bool _etat)
{
    //    QMessageBox message;
    //    message.setText("Changement d'état");
    //    message.exec();
    QPalette palette;
    labelEtatCapot.setAutoFillBackground(true);
    if(_etat)
    {
        palette.setColor(QPalette::WindowText,Qt::black);
        labelEtatCapot.setPalette(palette);
        labelEtatCapot.setText("| Capot Fermé |");
    }
    else
    {
        palette.setColor(QPalette::WindowText,Qt::red);
        labelEtatCapot.setPalette(palette);
        labelEtatCapot.setText("| Capot Ouvert |");
        on_pushButton_Arreter_clicked();
    }
}

void Equlibreuse::on_pushButton_Lancer_clicked()
{
    ui->pushButton_Lancer->setText("Fixer Consigne");
    leMoteur->FixerConsigneVitesse(ui->lcdNumber_consigne->value());
    leCodeur->LancerMesureVitesse();
}


void Equlibreuse::on_pushButton_Arreter_clicked()
{
     ui->pushButton_Lancer->setText("Lancer Moteur");
     leMoteur->FixerConsigneVitesse(0);
     ui->lcdNumber_consigne->display(0);
     ui->dial_ConsigneVitesse->setValue(0);
     leCodeur->ArreterMesureVitesse();
}

void Equlibreuse::on_dial_ConsigneVitesse_valueChanged(int value)
{
    ui->lcdNumber_consigne->display(value);
}

void Equlibreuse::onCodeur_NouvelleVitesse(int vitesse)
{
    ui->lcdNumberVitesse->display(vitesse);
}

