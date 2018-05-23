//-----------------------------------------------------------------------------------
#ifndef __CGAME_H__
#define __CGAME_H__
//-----------------------------------------------------------------------------------
#include <QString>
//-----------------------------------------------------------------------------------
#define NB_LIGNE                    7
#define NB_COLONNE                  7
#define NB_CASE                     (NB_LIGNE*NB_COLONNE)
#define MUR                         'M'
#define CROIX                       '+'
#define DEPART                      'T'
#define DQUART                      'X'
#define HORIZ                       '-'
#define QUART                       'r'
//-----------------------------------------------------------------------------------
typedef enum { ecoNone = 0, ecoBouge = 1, ecoTourne = 2, ecoDepart = 4, ecoArrive = 8, ecoR90 = 16, ecoR180 = 32, ecoR270 = 64, ecoNORot = 112} ECaseOption;
//-----------------------------------------------------------------------------------
typedef struct _SCase {
    char type;
    ECaseOption option;
}SCase;
//-----------------------------------------------------------------------------------
class CGame {
public:
    void load(QString fileName);
    void write(QString fileName);
    void init(void);
    void setPict(char type, int x, int y);
    const SCase& getCase(int x, int y);
    const SCase& getCase(int idx);
    void resetRotate(int x, int y);
    void resetRotate(int idx);
    void addRotate(ECaseOption rotateType, int x, int y);
    void addRotate(ECaseOption rotateType, int idx);
    void setOption(ECaseOption option, bool value, int x, int y);
    void melange(int step);
private:
    SCase plateau[NB_CASE];

    void move(int from, int to);
};
//-----------------------------------------------------------------------------------
#endif // __CGAME_H__
//-----------------------------------------------------------------------------------
