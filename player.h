#ifndef PLAYER_H
#define PLAYER_H
#include "gameobject.h"
#include "batiment.h"
#include <vector>
#include <iostream>
#include "unit.h"
using namespace std;

class Player {
    int money;
public:
    explicit Player(int m = 0);
    void earnmoney();
    void buyUnit(int t,Batiment* bat);
    void resetUnit();

    vector <Unit*> unitlist;
    vector <Batiment*> batlist;
};


#endif // PLAYER_H
