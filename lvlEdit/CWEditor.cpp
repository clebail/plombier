//-----------------------------------------------------------------------------------
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
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
		
		emit(tuilleChange(game.getCase(x, y)));
    }
}
//-----------------------------------------------------------------------------------
void CWEditor::droite(void) {
    if(x < NB_COLONNE - 1) {
        x++;
        repaint();
		
		emit(tuilleChange(game.getCase(x, y)));
    }

}
//-----------------------------------------------------------------------------------
void CWEditor::bas(void) {
    if(y < NB_LIGNE - 1) {
        y++;
        repaint();
		
		emit(tuilleChange(game.getCase(x, y)));
    }
}
//-----------------------------------------------------------------------------------
void CWEditor::gauche(void) {
    if(x) {
        x--;
        repaint();
		
		emit(tuilleChange(game.getCase(x, y)));
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
void CWEditor::setOption(ECaseOption option, bool value) {
    game.setOption(option, value,  x, y);
}
//-----------------------------------------------------------------------------------
void CWEditor::init(void) {
    game.init();

    repaint();
}
//-----------------------------------------------------------------------------------
void CWEditor::load(QString fileName) {
    game.load(fileName);

    repaint();
}
//-----------------------------------------------------------------------------------
void CWEditor::write(QString fileName) {
    game.write(fileName);
}
//-----------------------------------------------------------------------------------
void CWEditor::melange(int step) {
    game.melange(step);

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
            QImage img;

            switch(tuille.type) {
            case MUR:
                img = rotate(QImage(picts[MUR]), tuille.option);
                break;
            case CROIX:
                img = rotate(QImage(picts[CROIX]), tuille.option);
                break;
            case DEPART:
                img = rotate(QImage(picts[DEPART]), tuille.option);
                break;
            case DQUART:
                img = rotate(QImage(picts[DQUART]), tuille.option);
                break;
            case HORIZ:
                img = rotate(QImage(picts[HORIZ]), tuille.option);
                break;
            case QUART:
                img = rotate(QImage(picts[QUART]), tuille.option);
                break;
            }

            if(!img.isNull()) {
                painter.drawImage(x * CASE_WIDTH, y * CASE_HEIGHT, img);
            }
        }
    }

    cursorPen.setStyle(Qt::DashLine);
    cursorPen.setWidth(2);
    painter.setPen(cursorPen);
    painter.drawRect(this->x * CASE_WIDTH + 2, this->y * CASE_HEIGHT + 2, CASE_WIDTH - 4, CASE_HEIGHT - 4);

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
void CWEditor::mousePressEvent(QMouseEvent *event) {
    x = event->x() / CASE_WIDTH;
    y = event->y() / CASE_HEIGHT;

    repaint();
}
//-----------------------------------------------------------------------------------
QImage CWEditor::rotate(const QImage &image, ECaseOption option) {
    QMatrix matrix;
    QImage result = image;
	QPoint center = image.rect().center();

    matrix.translate(center.x(), center.y());

    if((option & ecoR90) == ecoR90) {
        matrix.rotate(90);
        result = image.transformed(matrix);
    }

    if((option & ecoR180) == ecoR180) {
        matrix.rotate(180);
        result =  image.transformed(matrix);
    }

    if((option & ecoR270) == ecoR270) {
        matrix.rotate(270);
        result =  image.transformed(matrix);
    }

    return result;
}
//-----------------------------------------------------------------------------------
