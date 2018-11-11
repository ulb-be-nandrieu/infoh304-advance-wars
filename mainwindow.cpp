#include "head.h"

#include <QApplication>
#include <QPainter>
#include <QKeyEvent>
#include <QLabel>
#include <vector>
#include <iostream>
using namespace std;

int const sizecase = min(sizewindowsx/sizemapx,sizewindowsy/sizemapy);

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->p0 = new Player(10000);
    this->p1 = new Player(10000);
    this->actif = p0;
    this->inactif = p1;

    int typemap[sizemap];
    typemap[0] = 1;
    typemap[1] = 2;
    typemap[2] = 1;
    typemap[3] = 1;
    typemap[4] = 2;
    typemap[5] = 1;
    typemap[6] = 2;
    typemap[7] = 1;
    typemap[8] = 1;
    typemap[9] = 6;
    typemap[10] = 7;
    typemap[11] = 2;
    typemap[12] = 1;
    typemap[13] = 1;
    typemap[14] = 2;
    typemap[15] = 1;
    typemap[16] = 2;
    typemap[17] = 1;
    typemap[18] = 1;
    typemap[19] = 1;

    for (int i=0;i<sizemap;i++){
        this->ter.push_back(new Terrain(i%sizemapx,i/sizemapx,typemap[i]));
        if (typemap[i]==6){
            Batiment *bat = static_cast<Batiment*>(ter[i]);
            bat->setcamp(0);
            p0->batlist.push_back(bat);
            allbat.push_back(bat);
        } else if (typemap[i]==7){
            Batiment *bat = static_cast<Batiment*>(ter[i]);
            bat->setcamp(1);
            p1->batlist.push_back(bat);
            allbat.push_back(bat);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::endturn(){
    if (actif == p0){
        actif = p1;
        inactif = p0;
        cout<<"fin tour 0"<<endl;
    } else {
        actif = p0;
        inactif = p1;
        cout<<"fin tour 1"<<endl;
    }
    actif->earnmoney();
    actif->resetUnit();
}
bool MainWindow::isobstacle(int posx, int posy){
    bool b = false;
    int l = p0->unitlist.size();
    for (int i = 0; i<l; i++){
        int x = p0->unitlist[i]->getposX();
        int y = p0->unitlist[i]->getposY();
        if ( x == posx and y == posy){
            b = true;
        }
    }
    int l2 = p1->unitlist.size();
    for (int i = 0; i<l2; i++){
        int x = p1->unitlist[i]->getposX();
        int y = p1->unitlist[i]->getposY();
        if ( x == posx and y == posy){
            b = true;
        }
    }

    return b;
}
void MainWindow::moveunit(int x, int y, Unit* unit){
    int xo = unit->getposX();
    int yo = unit->getposY();
    int dx = x-xo;
    int dy = y-yo;

    if (abs(dx)+abs(dy) <= unit->getmp()){
        for (int i = 0; i<abs(dx);i++){
            if (dx > 0){
                unit->move(1);
            } else {
                unit->move(3);

            }
        }
        for (int j = 0; j<abs(dy);j++){
            if (dy > 0){
                unit->move(0);
            } else {
                unit->move(2);

            }
        }
    } else {
        cout<<"pas possible"<<endl;
    }
}

void MainWindow::attaque(Unit* unit,int mx,int my){
    int xo = unit->getposX();
    int yo = unit->getposY();
    int dx = mx-xo;
    int dy = my-yo;
    if (abs(dx)+abs(dy) <=1 and unit->getatt()){
        int l = inactif->unitlist.size();
        for (int i = 0; i<l; i++){
            int x = inactif->unitlist[i]->getposX();
            int y = inactif->unitlist[i]->getposY();
            if (x == mx and y == my){
                int d = damage(unit,inactif->unitlist[i],x,y);
                bool b = inactif->unitlist[i]->attacked(d);
                if (b){
                    int d = damage(inactif->unitlist[i],unit,xo,yo);
                    bool a = unit->attacked(d);
                }
            }
        }
    }
    repaint();
}
void MainWindow::capture(){
    int xb = inactif->batlist[0]->getposX();
    int yb = inactif->batlist[0]->getposY();

    int l = actif->unitlist.size();
    for (int i = 0; i<l; i++){
        int x = actif->unitlist[i]->getposX();
        int y = actif->unitlist[i]->getposY();
        if (x == xb and y == yb){
            //actif->batlist.push_back(inactif->batlist[0]);
            if (inactif->batlist[0]->getcamp()==1){
                inactif->batlist[0]->setcamp(0);
            } else if (inactif->batlist[0]->getcamp()==0){
                inactif->batlist[0]->setcamp(1);
            }
            //delete inactif->batlist[0];
            //endgame();
        }
    }
    repaint();
}
void MainWindow::endgame(){
    if (p0->batlist.size()==0){
        cout <<"player 2 win"<<endl;
    } else if (p1->batlist.size()==0){
        cout <<"player 1 win"<<endl;
    }
}

int MainWindow::damage(Unit* ua, Unit* ud,int x,int y){
    /*int ta = ua->gettype();
    int td = ud->gettype();

    int B[11][11];

    int b = B[ta][td];
    int def = ter[y*sizemapx + x]->def;
    int d = b*ua->pv/10*(100-def*ud->pv)/100;*/

    return 5;
}

void MainWindow::paintEvent(QPaintEvent* event){
   QPainter painter(this);
   QPixmap plain(":/images/terrain/1_plain.gif");
   QPixmap mountain(":/images/terrain/2_mountain.gif");
   QPixmap getank(":/images/units/getank.gif");
   QPixmap geinfantry(":/images/units/geinfantry.gif");
   for (int i=0;i<sizemap;i++){
        int t = ter[i]->gettype();
        int x = ter[i]->getposX();
        int y = ter[i]->getposY();
        if (t == 1){
            painter.drawPixmap(x*(sizecase+2),y*(sizecase+2),sizecase,sizecase,plain);
        } else if (t == 2){
            painter.drawPixmap(x*(sizecase+2),y*(sizecase+2),sizecase,sizecase,mountain);
        } /*else {
            if (ter[i] == 0){
                painter.fillRect(x*(sizecase+2),y*(sizecase+2),sizecase,sizecase,Qt::blue);
            } else if (t == 1){
                painter.fillRect(x*(sizecase+2),y*(sizecase+2),sizecase,sizecase,Qt::blue);
            }
        }*/
   }
   int l = allbat.size();
   for (int i = 0; i<l; i++){
       int x = allbat[i]->getposX();
       int y = allbat[i]->getposY();
       int c = allbat[i]->getcamp();
       if (c == 0){
          painter.fillRect(x*(sizecase+2),y*(sizecase+2),sizecase,sizecase,Qt::blue);
       } else {
          painter.fillRect(x*(sizecase+2),y*(sizecase+2),sizecase,sizecase,Qt::red);
       }
   }
   int l0 = p0->unitlist.size();
   for (int i = 0; i<l0; i++){
       int x = p0->unitlist[i]->getposX();
       int y = p0->unitlist[i]->getposY();
       painter.drawPixmap(x*(sizecase+2),y*(sizecase+2),sizecase,sizecase,getank);
   }
   int l1 = p1->unitlist.size();
   for (int i = 0; i<l1; i++){
       int x = p1->unitlist[i]->getposX();
       int y = p1->unitlist[i]->getposY();
       painter.drawPixmap(x*(sizecase+2),y*(sizecase+2),sizecase,sizecase,geinfantry);
   }

}

void MainWindow::keyPressEvent(QKeyEvent* event){
    switch (event->key()) {
    case Qt::Key_A:
        endturn();
        break;
    case Qt::Key_E:
        capture();
        break;
    case Qt::Key_Z:
        if (isobstacle(actif->batlist[0]->getposX(),actif->batlist[0]->getposY())==false){
            actif->buyUnit(0,actif->batlist[0]);
        } else {
            cout<<"pas place"<<endl;
        }
        break;
    }
    repaint();
}


void MainWindow::mousePressEvent(QMouseEvent *event){
    int mx = event->x()/sizecase;
    int my = event->y()/sizecase;

    int l = actif->unitlist.size();
    for (int i = 0; i<l; i++){
        if (actif->unitlist[i]->getselected()){
            if (isobstacle(mx,my)==false){
                moveunit(mx, my, actif->unitlist[i]);
            } else {
                attaque(actif->unitlist[i],mx,my);
            }
        }
    }
    for (int i = 0; i<l; i++){
        int x = actif->unitlist[i]->getposX();
        int y = actif->unitlist[i]->getposY();
        if (x==mx and y==my){
            if (actif->unitlist[i]->getselected() == false){
                actif->unitlist[i]->setselected(true);
            } else {
                actif->unitlist[i]->setselected(false);
            }
        }
    }
    repaint();
}
