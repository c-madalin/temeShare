#include "myview.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsPolygonItem>
#include <QKeyEvent>
#include <QPen>
#include <cmath>
#include <QDebug>
#include <algorithm>
#include <numeric>

MyView::MyView(QWidget *parent) : QGraphicsView(parent), m_isFirstNodeSelected(false), m_selectedNode(nullptr)
{
    scene = new QGraphicsScene(this);
    this->setScene(scene);
    this->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);
}

void MyView::run()
{
    this->show();
}

void MyView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // Adaugă un nod nou la click stânga
        if (m_graf.addNode(event->pos())) {
            Node &newNode = m_graf.getNodes().back();
            drawNode(newNode.getPos().x(), newNode.getPos().y(), newNode.getValue());
        }
    }
    else if (event->button() == Qt::RightButton)
    {
        // Selectează noduri și adaugă o muchie între ele
        std::vector<Node> &nodes = m_graf.getNodes();
        for (auto &node : nodes)
        {
            int distSquared = (node.getPos().x() - event->pos().x()) * (node.getPos().x() - event->pos().x()) +
                              (node.getPos().y() - event->pos().y()) * (node.getPos().y() - event->pos().y());
            if (distSquared < 400)
            {
                if (m_isFirstNodeSelected)
                {
                    // Adaugă muchie între nodul selectat anterior și nodul curent
                    if (m_graf.addEdge(*m_selectedNode, node))
                    {
                        drawLine(m_selectedNode->getPos().x(), m_selectedNode->getPos().y(),
                                  node.getPos().x(), node.getPos().y());
                    }
                    m_isFirstNodeSelected = false;
                    m_selectedNode = nullptr;
                }
                else
                {
                    m_isFirstNodeSelected = true;
                    m_selectedNode = &node;
                }
                break;
            }
        }
    }
}


Graf& MyView::getGraf()
{
    return m_graf;
}


void MyView::drawNode(int x, int y, int value)
{
    QGraphicsEllipseItem *nodeItem = new QGraphicsEllipseItem(x - 20, y - 20, 40, 40);
    nodeItem->setPen(QPen(Qt::white, 2)); // Contur alb
    //nodeItem->setBrush(Qt::black); // Umplere neagră
    scene->addItem(nodeItem);

    QGraphicsTextItem *textItem = new QGraphicsTextItem(QString::number(value));
    textItem->setDefaultTextColor(Qt::green);
    textItem->setPos(x - 6, y - 12);
    scene->addItem(textItem);
}

void MyView::drawLine(int startX, int startY, int endX, int endY)
{
    QLineF line(QPointF(startX, startY), QPointF(endX, endY));
    double length = line.length();

    const double nodeRadius = 20.0;
    QPointF startAdjusted = line.pointAt(nodeRadius / length);
    QPointF endAdjusted = line.pointAt((length - nodeRadius) / length);

    // Desenăm linia dintre cele două noduri
    QGraphicsLineItem *lineItem = new QGraphicsLineItem(QLineF(startAdjusted, endAdjusted));
    lineItem->setPen(QPen(Qt::white, 2));
    scene->addItem(lineItem);

    // Calculăm poziția textului
    QPointF midpoint = line.center(); // Mijlocul liniei

    double cost = std::sqrt(std::pow(endX - startX, 2) + std::pow(endY - startY, 2));

    QGraphicsTextItem *costText = new QGraphicsTextItem(QString::number(cost, 'f', 2)); // 2 zecimale
    costText->setDefaultTextColor(Qt::red);
    costText->setPos(midpoint.x() - 20, midpoint.y() - 20);
    scene->addItem(costText);
}

///////////////////////////////
void MyView::redraw()
{
    scene->clear(); // Șterge tot din scenă

    // Reafișează nodurile
    for (const Node& node : m_graf.getNodes())
    {
        drawNode(node.getPos().x(), node.getPos().y(), node.getValue());
    }

    // Reafișează muchiile
    for (const Edge& edge : m_graf.getEdges())
    {
        drawLine(edge.getFirst().getPos().x(), edge.getFirst().getPos().y(),
                  edge.getSecond().getPos().x(), edge.getSecond().getPos().y());
    }
}

void MyView::drawGenericTree()
{
    redraw(); // Curăță scena și afișează graful original

    auto genericTreeEdges = m_graf.getGenericTree(); // Obține arborele din algoritmul Generic
    for (const Edge& edge : genericTreeEdges)
    {
        // Colorează muchiile arborelui rezultat (verde, de exemplu)
        QGraphicsLineItem* lineItem = new QGraphicsLineItem(QLineF(edge.getFirst().getPos(), edge.getSecond().getPos()));
        lineItem->setPen(QPen(Qt::green, 3));
        scene->addItem(lineItem);
    }
}
void MyView::drawKruskalTree()
{
    redraw(); // Curăță scena și afișează graful original

    auto kruskalTreeEdges = m_graf.getKruskalTree(); // Obține arborele din algoritmul Kruskal
    for (const Edge& edge : kruskalTreeEdges)
    {
        // Colorează muchiile arborelui rezultat (albastru, de exemplu)
        QGraphicsLineItem* lineItem = new QGraphicsLineItem(QLineF(edge.getFirst().getPos(), edge.getSecond().getPos()));
        lineItem->setPen(QPen(Qt::blue, 3));
        scene->addItem(lineItem);
    }
}

void MyView::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_A)
    {
        drawGenericTree();
    }
    else if (event->key() == Qt::Key_S)
    {
        drawKruskalTree();
    }
    else if(event->key() == Qt::Key_Space)
    {
        redraw();
    }
    else
    {
        QGraphicsView::keyPressEvent(event);
    }
}
