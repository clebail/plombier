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
    void on_rb0_clicked(void);
    void on_rb90_clicked(void);
    void on_rb180_clicked(void);
    void on_rb270_clicked(void);
	void on_wEditor_tuilleChange(const SCase& tuille);
};
//-----------------------------------------------------------------------------------
#endif // __CMAINWINDOW_H__
//-----------------------------------------------------------------------------------
