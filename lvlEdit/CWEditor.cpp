//-----------------------------------------------------------------------------------
#include <QPainter>
#include <QKeyEvent>
#include <QtDebug>
#include "CWEditor.h"
//-----------------------------------------------------------------------------------
CWEditor::CWEditor(QWidget *parent) : QWidget(parent) {
    x = y = 0;

    picts[MUR] = ":/image/mur.png";
    picts[CROIX] = ":/image/tCroix.png";
    picts[DEPART] = ":/image/tDepartFin.png";
    picts[DQUART] = ":/image/tDQuart.png";
    picts[HORIZ] = ":/image/tHorizontal.png";
    picts[QUART] = ":/image/tQuart.png";

    game.init();
}
//-----------------------------------------------------------------------------------
void CWEditor::haut(void) {
    if(y) {
        y--;
        repaint();
    }
}
//-----------------------------------------------------------------------------------
void CWEditor::droite(void) {
    if(x < NB_COLONNE - 1) {
        x++;
        repaint();
    }

}
//-----------------------------------------------------------------------------------
void CWEditor::bas(void) {
    if(y < NB_LIGNE - 1) {
        y++;
        repaint();
    }
}
//-----------------------------------------------------------------------------------
void CWEditor::gauche(void) {
    if(x) {
        x--;
        repaint();
    }
}
//-----------------------------------------------------------------------------------
QString CWEditor::getPictResourceName(char type) {
    return picts[type];
}
//-----------------------------------------------------------------------------------
void CWEditor::setCasePict(char type) {
    game.setPict(type, x, y);

    repaint();
}
//-----------------------------------------------------------------------------------
void CWEditor::resetRotate(void) {
    game.resetRotate(x, y);

    repaint();
}
//-----------------------------------------------------------------------------------
void CWEditor::addRotate(ECaseOption rotateType) {
    game.addRotate(rotateType, x, y);

    repaint();
}
//-----------------------------------------------------------------------------------
void CWEditor::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPen cursorPen(Qt::red);
    int x, y, idx;

    for(y=idx=0;y<NB_LIGNE;y++) {
        for(x=0;x<NB_COLONNE;x++,idx++) {
            SCase tuille = game.getCase(idx);
            QImage pixmap;

            switch(tuille.type) {
            case MUR:
                pixmap = rotate(QImage(picts[MUR]), tuille.option);
                break;
            case CROIX:
                pixmap = rotate(QImage(picts[CROIX]), tuille.option);
                break;
            case DEPART:
                pixmap = rotate(QImage(picts[DEPART]), tuille.option);
                break;
            case DQUART:
                pixmap = rotate(QImage(picts[DQUART]), tuille.option);
                break;
            case HORIZ:
                pixmap = rotate(QImage(picts[HORIZ]), tuille.option);
                break;
            case QUART:
                pixmap = rotate(QImage(picts[QUART]), tuille.option);
                break;
            }

            if(!pixmap.isNull()) {
                painter.drawImage(x * CASE_WIDTH, y * CASE_HEIGHT, pixmap);
            }
        }
    }

    cursorPen.setStyle(Qt::DotLine);
    painter.setPen(cursorPen);
    painter.drawRect(this->x * CASE_WIDTH, this->y * CASE_HEIGHT, CASE_WIDTH, CASE_HEIGHT);

}
//-----------------------------------------------------------------------------------
void CWEditor::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
    case Qt::Key_Up:
        haut();
        break;
    case Qt::Key_Right:
        droite();
        break;
    case Qt::Key_Down:
        bas();
        break;
    case Qt::Key_Left:
        gauche();
        break;
    default:
        break;
    }
}
//-----------------------------------------------------------------------------------
QImage CWEditor::rotate(const QImage &image, ECaseOption option) {
    QMatrix matrix;
    QImage result = image;

    matrix.translate(CASE_WIDTH / 2, CASE_HEIGHT / 2);

    if(option & ecoR90 == ecoR90) {
        matrix.rotate(90);
        result = image.transformed(matrix);
    }

    if(option & ecoR180 == ecoR180) {
        matrix.rotate(180);
        result =  image.transformed(matrix);
    }

    if(option & ecoR270 == ecoR270) {
        matrix.rotate(270);
        result =  image.transformed(matrix);
    }

    return result;
}
//-----------------------------------------------------------------------------------
