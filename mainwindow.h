#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "terrain.h"
#include "player.h"
#include "nombre.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void moveunit(int x, int y, Unit* unit);
    void endturn();
    bool isobstacle(int x, int y);
    void attaque(Unit* unit,int mx,int my);
    int damage (Unit* ua, Unit* ud,int x,int y);
    void endgame();
    void capture();

private:
    vector <Terrain*> ter;
    vector <Batiment*> allbat; //bof
    Player* p0;
    Player* p1;
    Player* actif;
    Player* inactif;
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
