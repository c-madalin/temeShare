#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <iostream>
#include <fstream>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "graf.h"

class Maze : public QGraphicsView {
    Q_OBJECT

private:
    int cellSize = 50;
    std::vector<std::vector<int>> matrix;
    QGraphicsScene *scene;
    Graf graf;
    bool isGraphDisplayed=false;
    bool isSolved=false;

public:
    Maze();
    void readMatrix();
    void showMatrix();
    void drawMaze();
    void solve();
    void drawGraph(const Graf &graf);
    Graf getGraf()const{return graf;}
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MAZE_H
