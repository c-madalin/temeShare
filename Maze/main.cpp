#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <fstream>
#include "Maze.h"
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Maze maze;
    maze.readMatrix();
    maze.drawMaze();

    maze.show();
    maze.showMatrix();

    std::cout << "Nodes count: " << maze.getGraf().getNodes().size() << std::endl;
    std::cout << "Edges count: " << maze.getGraf().getEdges().size() << std::endl;
    std::cout<< "lungime path: "<< maze.getGraf().getPath().size()<<std::endl;
    for(int i=0;i<maze.getGraf().getPaths().size();i++)
    {
         std::cout<< "lungime path: "<<i<<" "<< maze.getGraf().getPaths()[i].size()<<std::endl;
    }
    //maze.getGraf().setExits();
    //maze.getGraf().showExits();
    //intrebare maine

    return a.exec();
}
