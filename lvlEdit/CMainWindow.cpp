//-----------------------------------------------------------------------------------
#include <QtDebug>
#include <QFileDialog>
#include <QInputDialog>
#include "CMainWindow.h"
//-----------------------------------------------------------------------------------
CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi(this);

    pbMur->setIcon(QIcon(wEditor->getPictResourceName(MUR)));
    pbCroix->setIcon(QIcon(wEditor->getPictResourceName(CROIX)));
    pbDepart->setIcon(QIcon(wEditor->getPictResourceName(DEPART)));
    pbDQuart->setIcon(QIcon(wEditor->getPictResourceName(DQUART)));
    pbHoriz->setIcon(QIcon(wEditor->getPictResourceName(HORIZ)));
    pbQuart->setIcon(QIcon(wEditor->getPictResourceName(QUART)));
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_pbMur_pressed(void) {
    wEditor->setCasePict(MUR);
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_pbCroix_pressed(void) {
    wEditor->setCasePict(CROIX);
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_pbDepart_pressed(void) {
    wEditor->setCasePict(DEPART);
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_pbDQuart_pressed(void) {
    wEditor->setCasePict(DQUART);
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_pbHoriz_pressed(void) {
    wEditor->setCasePict(HORIZ);
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_pbQuart_pressed(void) {
    wEditor->setCasePict(QUART);
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_pbVide_pressed(void) {
    wEditor->setCasePict(0);
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_rb0_clicked(void) {
    wEditor->resetRotate();
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_rb90_clicked(void) {
    wEditor->addRotate(ecoR90);
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_rb180_clicked(void) {
    wEditor->addRotate(ecoR180);
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_rb270_clicked(void) {
    wEditor->addRotate(ecoR270);
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_cbBouge_clicked(void) {
    wEditor->setOption(ecoBouge, cbBouge->isChecked());
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_cbTourne_clicked(void) {
    wEditor->setOption(ecoTourne, cbTourne->isChecked());
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_cbDepart_clicked(void) {
    wEditor->setOption(ecoDepart, cbDepart->isChecked());
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_cbArrive_clicked(void) {
    wEditor->setOption(ecoArrive, cbArrive->isChecked());
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_wEditor_tuilleChange(const SCase& tuille) {

    cbBouge->setChecked((tuille.option & ecoBouge) == ecoBouge);
    cbTourne->setChecked((tuille.option & ecoTourne) == ecoTourne);
    cbDepart->setChecked((tuille.option & ecoDepart) == ecoDepart);
    cbArrive->setChecked((tuille.option & ecoArrive) == ecoArrive);

	rb0->setChecked(true);
	if((tuille.option & ecoR90) == ecoR90) {
		rb90->setChecked(true);
	}
	if((tuille.option & ecoR180) == ecoR180) {
		rb180->setChecked(true);
	}
	if((tuille.option & ecoR270) == ecoR270) {
		rb270->setChecked(true);
	}
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_actionNouveau_triggered(bool) {
    wEditor->init();
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_actionOuvrir_triggered(bool) {
    QString fileName = QFileDialog::getOpenFileName(this);
    if(fileName != "") {
        wEditor->load(fileName);
    }
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_actionEnregistrer_triggered(bool) {
    QString fileName = QFileDialog::getSaveFileName(this);
    if(fileName != "") {
        wEditor->write(fileName);
    }
    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------
void CMainWindow::on_pbMelange_pressed(void) {
    int step = 0;

    step = QInputDialog::getInt(this, "Nombre de passes", "Combien de passes ?", 3);
    if(step != 0) {
        wEditor->melange(step);
    }

    wEditor->setFocus();
}
//-----------------------------------------------------------------------------------

