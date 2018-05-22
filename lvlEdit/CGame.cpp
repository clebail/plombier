//-----------------------------------------------------------------------------------
#include <stdlib.h>
#include <QtDebug>
#include "CGame.h"
//-----------------------------------------------------------------------------------
void CGame::load(QString fileName) {

}
//-----------------------------------------------------------------------------------
void CGame::write(QString fileName) {

}
//-----------------------------------------------------------------------------------
void CGame::init(void) {
    memset(plateau, 0, NB_CASE * sizeof(SCase));
}
//-----------------------------------------------------------------------------------
void CGame::setPict(char type, int x, int y) {
    int idx = y * NB_COLONNE + x;

    plateau[idx].type = type;
}
//-----------------------------------------------------------------------------------
const SCase& CGame::getCase(int x, int y) {
   return getCase(y * NB_COLONNE + x);
}
//-----------------------------------------------------------------------------------
const SCase& CGame::getCase(int idx) {
    return plateau[idx];
}
//-----------------------------------------------------------------------------------
void CGame::resetRotate(int x, int y) {
    resetRotate(y * NB_COLONNE + x);
}
//-----------------------------------------------------------------------------------
void CGame::resetRotate(int idx) {
    plateau[idx].option = (ECaseOption)(plateau[idx].option | ecoNORot);
    plateau[idx].option = (ECaseOption)(plateau[idx].option ^ ecoNORot);
}
//-----------------------------------------------------------------------------------
void CGame::addRotate(ECaseOption rotateType, int x, int y) {
    int idx = y * NB_COLONNE + x;

    resetRotate(idx);
    plateau[idx].option = (ECaseOption)(plateau[idx].option | rotateType);
}
//-----------------------------------------------------------------------------------
