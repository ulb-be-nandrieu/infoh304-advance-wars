#include "head.h"

Terrain::Terrain(int x, int y, int t) : Gameobject (x,y)
{
    type = t;

    int chart[6][9];

    /* /!\ 0 = pas de déplacement possible*/

    /*0 - Plaine*/
    chart[1][0] = 1;    /*Defense*/
    chart[2][0] = 1;    /*Move Type F = 6*/
    chart[3][0] = 1;    /*Move Type T = 20*/
    chart[4][0] = 2;    /*Move Type W = 23*/
    chart[5][0] = 1;    /*Move Type A = 1*/

    /*1 - Montagne*/
    chart[1][1] = 4;    /*Defense*/
    chart[2][1] = 2;    /*Move Type F = 6*/
    chart[3][1] = 0;    /*Move Type T = 20*/
    chart[4][1] = 0;    /*Move Type W = 23*/
    chart[5][1] = 1;    /*Move Type A = 1*/

    /*2 - Forêt*/
    chart[1][2] = 2;    /*Defense*/
    chart[2][2] = 1;    /*Move Type F = 6*/
    chart[3][2] = 2;    /*Move Type T = 20*/
    chart[4][2] = 3;    /*Move Type W = 23*/
    chart[5][2] = 1;    /*Move Type A = 1*/

    /*3 - Eau*/
    chart[1][3] = 0;    /*Defense*/
    chart[2][3] = 0;    /*Move Type F = 6*/
    chart[3][3] = 0;    /*Move Type T = 20*/
    chart[4][3] = 0;    /*Move Type W = 23*/
    chart[5][3] = 1;    /*Move Type A = 1*/

    /*4 - Route*/
    chart[1][4] = 0;    /*Defense*/
    chart[2][4] = 1;    /*Move Type F = 6*/
    chart[3][4] = 1;    /*Move Type T = 20*/
    chart[4][4] = 1;    /*Move Type W = 23*/
    chart[5][4] = 1;    /*Move Type A = 1*/

    /*5 - Pont*/
    chart[1][5] = 0;    /*Defense*/
    chart[2][5] = 1;    /*Move Type F = 6*/
    chart[3][5] = 1;    /*Move Type T = 20*/
    chart[4][5] = 1;    /*Move Type W = 23*/
    chart[5][5] = 1;    /*Move Type A = 1*/

    /*6 - Ville*/
    chart[1][6] = 3;    /*Defense*/
    chart[2][6] = 1;    /*Move Type F = 6*/
    chart[3][6] = 1;    /*Move Type T = 20*/
    chart[4][6] = 1;    /*Move Type W = 23*/
    chart[5][6] = 1;    /*Move Type A = 1*/

    /*7- Usine*/
    chart[1][7] = 3;    /*Defense*/
    chart[2][7] = 1;    /*Move Type F = 6*/
    chart[3][7] = 1;    /*Move Type T = 20*/
    chart[4][7] = 1;    /*Move Type W = 23*/
    chart[5][7] = 1;    /*Move Type A = 1*/

    /*8 - Aéroport*/
    chart[1][8] = 3;    /*Defense*/
    chart[2][8] = 1;    /*Move Type F = 6*/
    chart[3][8] = 1;    /*Move Type T = 20*/
    chart[4][8] = 1;    /*Move Type W = 23*/
    chart[5][8] = 1;    /*Move Type A = 1*/

    def = chart[1][t];
}

int Terrain::gettype(){
    return this->type;
}

int Terrain::getdef(){
    return this->def;
}
