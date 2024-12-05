#include "Maze.h"
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <algorithm>
#include <QGraphicsTextItem>

Maze::Maze() {
    scene = new QGraphicsScene(this);
    setScene(scene);
    std::cout<<"obiect creat"<<std::endl;
    graf.setMatrix();
    graf.createGraf();
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

            if (matrix[x][y] == 2) continue;
            if (matrix[x][y] == 3) continue;

            QGraphicsRectItem *rect = scene->addRect(y * cellSize, x * cellSize, cellSize, cellSize);
            rect->setBrush(QBrush(Qt::green));
            rect->setPen(Qt::NoPen);
        }
    }
    scene->setSceneRect(0, 0, matrix[0].size() * cellSize, matrix.size() * cellSize);
}

void Maze::drawGraph(const Graf &graf) {
    scene->clear();

    QPen nodePen(Qt::white);  //
    nodePen.setWidth(2); //

    QPen edgePen(Qt::gray); //
    edgePen.setWidth(2);

    int nodeRadius = 15; //

    // Desenează nodurile
    for (const Node &node : graf.getNodes()) {
        QPointF pos = node.getPos();
        int x = pos.y() * cellSize;
        int y = pos.x() * cellSize;

        QGraphicsEllipseItem *nodeItem = scene->addEllipse(
            x - nodeRadius, y - nodeRadius,
            nodeRadius * 2, nodeRadius * 2,
            nodePen
            );

        QGraphicsTextItem *textItem = scene->addText(QString::number(node.getValue()));

        QFont font;
        font.setPointSize(12);
        textItem->setFont(font);

        textItem->setDefaultTextColor(Qt::red);  //

        textItem->setPos(x - textItem->boundingRect().width() / 2, y - textItem->boundingRect().height() / 2);
        textItem->setZValue(1);

        nodeItem->setToolTip("Node: (" + QString::number(node.getPos().x()) + ", " + QString::number(node.getPos().y()) + ")");
    }

    for (const Edge &edge : graf.getEdges()) {
        QPointF startPos = edge.getFirst().getPos();
        QPointF endPos = edge.getSecond().getPos();

        int x1 = startPos.y() * cellSize;
        int y1 = startPos.x() * cellSize;
        int x2 = endPos.y() * cellSize;
        int y2 = endPos.x() * cellSize;

        double angle = atan2(y2 - y1, x2 - x1);
        int offsetX = cos(angle) * nodeRadius;
        int offsetY = sin(angle) * nodeRadius;

        x1 += offsetX;
        y1 += offsetY;
        x2 -= offsetX;
        y2 -= offsetY;

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

