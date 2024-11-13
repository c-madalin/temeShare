#include "Maze.h"
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <algorithm>

Maze::Maze() {
    scene = new QGraphicsScene(this);
    setScene(scene);
    std::cout<<"obiect creat"<<std::endl;
    graf.setMatrix();
    graf.createGraf();
    graf.setPath();
    graf.setPaths();

}

void Maze::readMatrix() {
    std::ifstream f("C:\\Desktop\\facultate folder\\sem3\\AG\\Maze\\mazeMatrix.txt");

    if (!f.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    int n, m;
    f >> n >> m;

    matrix.resize(n, std::vector<int>(m));
    //m_grafMatrix.resize(n, std::vector<int>(m));
   //oare putem sa initializam matricea grafului direct de acii?
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f >> matrix[i][j];
           //m_grafMatrix[i][j]= matrix[i][j]
        }
    }

    f.close();
}

void Maze::showMatrix() {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Maze::drawMaze() {
    scene->clear();
    this->resize(800, 600);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            QGraphicsRectItem *rect = scene->addRect(j * cellSize, i * cellSize, cellSize, cellSize);

            switch (matrix[i][j]) {
            case 0: // Walls
                rect->setBrush(QBrush(Qt::black));
                break;
            case 1: // Paths
                rect->setBrush(QBrush(Qt::white));
                break;
            case 2: // Exits
                rect->setBrush(QBrush(Qt::red));
                break;
            case 3: // Entry
                rect->setBrush(QBrush(Qt::blue));
                break;
            default:
                rect->setBrush(QBrush(Qt::gray));
                break;
            }
            rect->setPen(Qt::NoPen);
        }
    }

    // Adjust scene size based on matrix dimensions
    scene->setSceneRect(0, 0, matrix[0].size() * cellSize, matrix.size() * cellSize);
}

void Maze::solve()
{
    scene->clear();
    this->resize(800, 600);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            QGraphicsRectItem *rect = scene->addRect(j * cellSize, i * cellSize, cellSize, cellSize);

            switch (matrix[i][j]) {
            case 0: // Walls
                rect->setBrush(QBrush(Qt::black));
                break;
            case 1: // Paths
                rect->setBrush(QBrush(Qt::white));
                break;
            case 2: // Exits
                rect->setBrush(QBrush(Qt::red));
                break;
            case 3: // Entry
                rect->setBrush(QBrush(Qt::blue));
                break;
            default:
                rect->setBrush(QBrush(Qt::gray));
                break;
            }
            rect->setPen(Qt::NoPen);
        }
    }

    const auto& allPaths = getGraf().getPaths();
    for (const auto& path : allPaths) {
        for (const Node& n : path) {
            int x = n.getPos().x();
            int y = n.getPos().y();

            // Verificăm tipul inițial al celulei pentru a nu suprascrie culorile intrării și ieșirilor
            if (matrix[x][y] == 2) continue; // Nu suprascrie ieșirile (roșu)
            if (matrix[x][y] == 3) continue; // Nu suprascrie intrarea (albastru)

            QGraphicsRectItem *rect = scene->addRect(y * cellSize, x * cellSize, cellSize, cellSize);
            rect->setBrush(QBrush(Qt::green));
            rect->setPen(Qt::NoPen);
        }
    }
    scene->setSceneRect(0, 0, matrix[0].size() * cellSize, matrix.size() * cellSize);
}

void Maze::drawGraph(const Graf &graf) {
    scene->clear();

    QPen nodePen(Qt::black);
    QBrush startBrush(Qt::blue);
    QBrush exitBrush(Qt::red);
    QBrush normalBrush(Qt::yellow);

    QPen edgePen(Qt::gray);
    edgePen.setWidth(2);

    int nodeRadius = 10; // Dimensiune nod

    // Desenează nodurile
    for (const Node &node : graf.getNodes()) {
        QPointF pos = node.getPos();
        int x = pos.y() * cellSize;  // ajustare pentru poziționare pe ecran
        int y = pos.x() * cellSize;

        // Alege culoarea în funcție de tipul nodului
        QBrush nodeBrush;
        if (node.getType() == 3) {
            nodeBrush = startBrush;
        } else if (node.getType() == 2) {
            nodeBrush = exitBrush;
        } else { // Nod normal
            nodeBrush = normalBrush;
        }


        QGraphicsEllipseItem *nodeItem = scene->addEllipse(
            x - nodeRadius, y - nodeRadius,
            nodeRadius * 2, nodeRadius * 2,
            nodePen, nodeBrush
            );

        nodeItem->setToolTip("Node: (" + QString::number(node.getPos().x()) + ", " + QString::number(node.getPos().y()) + ")");
    }

    for (const Edge &edge : graf.getEdges()) {
        QPointF startPos = edge.getFirst().getPos();
        QPointF endPos = edge.getSecond().getPos();
        int x1 = startPos.y() * cellSize;
        int y1 = startPos.x() * cellSize;
        int x2 = endPos.y() * cellSize;
        int y2 = endPos.x() * cellSize;
        scene->addLine(x1, y1, x2, y2, edgePen);
    }

    scene->setSceneRect(0, 0, matrix[0].size() * cellSize, matrix.size() * cellSize);
}


void Maze::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        if (isGraphDisplayed) {
            scene->clear();
            drawMaze();
        } else {

            scene->clear();
            drawGraph(graf);
        }
        isGraphDisplayed = !isGraphDisplayed;
    }
    if (event->key() == Qt::Key_S)
    {
    if (isSolved) {
        scene->clear();
        drawMaze();
    } else {

        scene->clear();
        solve();
    }
    isSolved = !isSolved;
}

}

