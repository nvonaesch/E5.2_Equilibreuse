#ifndef EQULIBREUSE_H
#define EQULIBREUSE_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLabel>

#include "codeur.h"
#include "mcculdaq.h"
#include "moteur.h"
#include "capot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Equlibreuse; }
QT_END_NAMESPACE

class Equlibreuse : public QMainWindow
{
    Q_OBJECT

public:
    Equlibreuse(QWidget *parent = nullptr);
    ~Equlibreuse();

private slots:
    void onCapot_EtatCapotChange(bool _etat);
    void on_pushButton_Lancer_clicked();

    void on_pushButton_Arreter_clicked();

    void on_dial_ConsigneVitesse_valueChanged(int value);
    void onCodeur_NouvelleVitesse(int vitesse);
private:
    Ui::Equlibreuse *ui;
    MccUldaq laCarte;
    Moteur *leMoteur;
    Capot *leCapot;
    QLabel labelEtatCapot;
    Codeur *leCodeur;
};
#endif // EQULIBREUSE_H
