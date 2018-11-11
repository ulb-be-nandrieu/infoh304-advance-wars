#include "head.h"

Batiment::Batiment(int x, int y, int t, int c) : Terrain (x,y,t)
{
    camp = c;
}

void Batiment::setcamp(int c){
    this->camp = c;
}
int Batiment::getcamp(){
    return this->camp;
}
