//-----------------------------------------------------------------------------------
#ifndef __CMAINWINDOW_H__
#define __CMAINWINDOW_H__
//-----------------------------------------------------------------------------------
#include <QMainWindow>
#include "ui_CMainWindow.h"
//-----------------------------------------------------------------------------------
class CMainWindow : public QMainWindow, private Ui::CMainWindow {
    Q_OBJECT
public:
    explicit CMainWindow(QWidget *parent = 0);
private slots:
    void on_pbMur_pressed(void);
    void on_pbCroix_pressed(void);
    void on_pbDepart_pressed(void);
    void on_pbDQuart_pressed(void);
    void on_pbHoriz_pressed(void);
    void on_pbQuart_pressed(void);
    void on_pbVide_pressed(void);
    void on_rb0_clicked(void);
    void on_rb90_clicked(void);
    void on_rb180_clicked(void);
    void on_rb270_clicked(void);
    void on_cbBouge_clicked(void);
    void on_cbTourne_clicked(void);
    void on_cbDepart_clicked(void);
    void on_cbArrive_clicked(void);
	void on_wEditor_tuilleChange(const SCase& tuille);
    void on_actionNouveau_triggered(bool checked = false);
    void on_actionOuvrir_triggered(bool checked = false);
    void on_actionEnregistrer_triggered(bool checked = false);
    void on_pbMelange_pressed(void);
};
//-----------------------------------------------------------------------------------
#endif // __CMAINWINDOW_H__
//-----------------------------------------------------------------------------------
