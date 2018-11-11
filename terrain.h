#ifndef TERRAIN_H
#define TERRAIN_H
#include "gameobject.h"

class Terrain: public Gameobject
{
    int type;
    int def;
public:
    Terrain(int x, int y, int t);
    int gettype();
    int getdef();
};

#endif // TERRAIN_H
