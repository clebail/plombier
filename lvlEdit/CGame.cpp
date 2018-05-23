//-----------------------------------------------------------------------------------
#include <stdlib.h>
#include <time.h>
#include <QFile>
#include <QtDebug>
#include "CGame.h"
//-----------------------------------------------------------------------------------
void CGame::load(QString fileName) {
    QFile file(fileName);

    if(file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        int idx = 0;

        while(!in.atEnd()) {
            QString line = in.readLine();
            int opt;
            QTextStream(&line) >> plateau[idx].type >> opt;
            plateau[idx].option = (ECaseOption)opt;
            if(plateau[idx].type == '0') {
                plateau[idx].type = 0;
            }

            idx++;
        }

        file.close();
    }
}
//-----------------------------------------------------------------------------------
void CGame::write(QString fileName) {
    QFile file(fileName);

    if(file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        int x, y, idx;

        for(y=idx=0;y<NB_LIGNE;y++) {
            for(x=0;x<NB_COLONNE;x++,idx++) {
                out << (plateau[idx].type != 0 ? plateau[idx].type  : '0') << " " << (int)plateau[idx].option << endl;
            }
        }

        file.close();
    }
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
    addRotate(rotateType, y * NB_COLONNE + x);
}
//-----------------------------------------------------------------------------------
void CGame::addRotate(ECaseOption rotateType, int idx) {
    resetRotate(idx);
    plateau[idx].option = (ECaseOption)(plateau[idx].option | rotateType);
}
//-----------------------------------------------------------------------------------
void CGame::setOption(ECaseOption option, bool value, int x, int y) {
    int idx = y * NB_COLONNE + x;

    plateau[idx].option = (ECaseOption)(plateau[idx].option | option);
    if(!value) {
        plateau[idx].option = (ECaseOption)(plateau[idx].option ^ option);
    }
}
//-----------------------------------------------------------------------------------
void CGame::melange(int step) {
    int i, x, y, idx;

    srand(time(NULL));

    for(i=0;i<step;i++) {
        for(y=idx=0;y<NB_LIGNE;y++) {
            for(x=0;x<NB_COLONNE;x++,idx++) {
                if((plateau[idx].option & ecoTourne) == ecoTourne) {
                    int rot = rand() % 4;
                    switch(rot) {
                    case 0:
                        resetRotate(idx);
                        break;
                    case 1:
                        addRotate(ecoR90, idx);
                        break;
                    case 2:
                        addRotate(ecoR180, idx);
                        break;
                    case 3:
                        addRotate(ecoR270, idx);
                        break;
                    }
                }

                if((plateau[idx].option & ecoBouge) == ecoBouge) {
                    bool fini = false;

                    while(!fini) {
                        int sens = rand() % 4;

                        switch(sens) {
                            case 0: //haut
                            if(y && plateau[idx-NB_COLONNE].type == 0) {
                                fini = true;

                                move(idx, idx-NB_COLONNE);
                            }
                            break;
                            case 1: //droite
                            if(x < NB_COLONNE - 1 && plateau[idx+1].type == 0) {
                                fini = true;

                                move(idx, idx+1);
                            }
                            break;
                            case 2: //bas
                            if(y < NB_LIGNE - 1 && plateau[idx+NB_COLONNE].type == 0) {
                                fini = true;

                                move(idx, idx+NB_COLONNE);
                            }
                            break;
                            case 3: //gauche
                            if(x && plateau[idx-1].type == 0) {
                                fini = true;

                                move(idx, idx-1);
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}
//-----------------------------------------------------------------------------------
void CGame::move(int from, int to) {
    plateau[to].type = plateau[from].type;
    plateau[to].option = plateau[from].option;

    plateau[from].type = 0;
    plateau[from].option = ecoNone;
}
//-----------------------------------------------------------------------------------
