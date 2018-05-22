//-----------------------------------------------------------------------------------
#ifndef __CWEDITOR_H__
#define __CWEDITOR_H__
//-----------------------------------------------------------------------------------
#include <QWidget>
#include <QHash>
#include "CGame.h"
#include "ui_CWEditor.h"
//-----------------------------------------------------------------------------------
#define CASE_WIDTH                  96
#define CASE_HEIGHT                 96
//-----------------------------------------------------------------------------------
class CWEditor : public QWidget {
    Q_OBJECT
public:
    explicit CWEditor(QWidget *parent = 0);
    void haut(void);
    void droite(void);
    void bas(void);
    void gauche(void);
    QString getPictResourceName(char type);
    void setCasePict(char type);
    void resetRotate(void);
    void addRotate(ECaseOption rotateType);
protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void keyPressEvent(QKeyEvent *);
private:
    int x, y;
    QHash<char, QString> picts;
    CGame game;

    QImage rotate(const QImage& image, ECaseOption option);
};
//-----------------------------------------------------------------------------------
#endif // __CWEDITOR_H__
//-----------------------------------------------------------------------------------
