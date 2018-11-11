#include "head.h"

Unit::Unit(int x, int y, int t) : Gameobject(x,y)
{
    type = t;

    int units[5][11];  /*Création tableau*/

    /*0 - Anti-air*/
    units[1][0] = 6;  /*MP*/
    units[2][0] = 9;    /*Ammo*/
    units[3][0] = 20; /*T*/  /*Move Type (Alphabet-->chiffre)*/
    units[4][0] = 8000; /*Cost*/

    /*1 - B-Copter*/
    units[1][1] = 6;
    units[2][1] = 6;
    units[3][1] = 1; /*A*/
    units[4][1] = 9000;

    /*2 - Bomber*/
    units[1][2] = 7;
    units[2][2] = 9;
    units[3][2] = 1; /*A*/
    units[4][2] = 22000;

    /*3 - Fighter*/
    units[1][3] = 9;
    units[2][3] = 9;
    units[3][3] = 1; /*A*/
    units[4][3] = 20000;

    /*4 - Infantry*/
    units[1][4] = 3;
    units[2][4] = 0;
    units[3][4] = 6; /*F*/
    units[4][4] = 1000;

    /*5 - Md.Tank*/
    units[1][5] = 5;
    units[2][5] = 8;
    units[3][5] = 20; /*T*/
    units[4][5] = 16000;

    /*6 - Mega Tank*/
    units[1][6] = 4;
    units[2][6] = 3;
    units[3][6] = 20; /*T*/
    units[4][6] = 28000;

    /*7 - Neotank*/
    units[1][7] = 6;
    units[2][7] = 9;
    units[3][7] = 20; /*T*/
    units[4][7] = 22000;

    /*8 - Recon*/
    units[1][8] = 8;
    units[2][8] = 0;
    units[3][8] = 23;/*W*/
    units[4][8] = 4000;

    /*9 - Tank*/
    units[1][9] = 6;
    units[2][9] = 9;
    units[3][9] = 20; /*T*/
    units[4][9] = 7000;

    this->mpmax = units[1][t];
    this->ammo = units[2][t];
    this->movetype = units[3][t];
    this->cost = units[4][t];
}

void Unit::move(int direction){
    if (mp > 0){
        if (direction == 0){
            posY ++;
        } else if (direction == 1){
            posX ++;
        } else if (direction == 2){
            posY --;
        } else {
            posX --;
        }
        mp--;
    }
}

int Unit::gettype(){
    return this->type;
}

bool Unit::attacked(int d){
    this->pv -=d;
    cout<<"pv"<<pv<<endl;
    if (pv <= 0){
        delete(this); //verif
        cout<<"unit mort"<<endl;
        return false;
    } else {
        return true;
    }

}

int Unit::getmp(){
    return this->mp;
}
int Unit::getmpmax(){
    return this->mpmax;
}
bool Unit::getatt(){
    return this->att;
}
bool Unit::getselected(){
    return this->selected;
}
int Unit::getcost(){
    return this->cost;
}
void Unit::setmp(int m){
    this->mp = m;
}
void Unit::setatt(bool a){
    this->att = a;
}
void Unit::setselected(bool a){
    this->selected = a;
}
