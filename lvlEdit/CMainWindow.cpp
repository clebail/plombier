//-----------------------------------------------------------------------------------
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
