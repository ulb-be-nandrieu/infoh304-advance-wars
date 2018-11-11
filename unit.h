#ifndef UNIT_H
#define UNIT_H

#include "gameobject.h"

class Unit: public Gameobject {
    int type;

    int ammo;
    int movetype;

    int mp = 0;
    int mpmax;
    int cost;
    int pv = 10;
    bool att = false;
    bool selected = false;


public :

    Unit(int x, int y, int t);
    void move(int direction);
    bool attacked(int d);

    int gettype();
    int getmp();
    int getmpmax();
    bool getatt();
    bool getselected();
    int getcost();

    void setmp(int m);
    void setatt(bool a);
    void setselected(bool a);


};

#endif // UNIT_H
