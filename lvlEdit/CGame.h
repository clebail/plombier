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
typedef enum { ecoBouge = 1, ecoTourne = 2, ecoDepart = 4, ecoR90 = 8, ecoR180 = 16, ecoR270 = 32, ecoNORot = 56} ECaseOption;
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
private:
    SCase plateau[NB_CASE];
};
//-----------------------------------------------------------------------------------
#endif // __CGAME_H__
//-----------------------------------------------------------------------------------
