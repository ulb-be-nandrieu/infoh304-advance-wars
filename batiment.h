#ifndef BATIMENT_H
#define BATIMENT_H
#include "terrain.h"

class Batiment: public Terrain
{
    int camp;

public:
    Batiment(int x, int y, int t,int c);
    void setcamp(int c);
    int getcamp();
};

#endif // BATIMENT_H
