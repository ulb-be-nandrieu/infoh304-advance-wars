#include "head.h"

Player::Player(int m){
    this->money = m;
}

void Player::earnmoney(){
    //int n = batlist.size();
    this->money += 1000;
}

void Player::buyUnit(int t,Batiment *bat){
    Unit* uni = new Unit(bat->getposX(),bat->getposY(),t);
    if (this->money > uni->getcost()){
        this->unitlist.push_back(uni);
        money -= uni->getcost();
    } else {
        delete uni;
        cout<<"pas de tune"<<endl;
    }

}

void Player::resetUnit() {
    int s = unitlist.size();
    for (int i = 0; i<s; i++){
        unitlist[i]->setmp(unitlist[i]->getmpmax());
        unitlist[i]->setatt(true);
        cout<<"mp reinit"<<endl;
    }
}
