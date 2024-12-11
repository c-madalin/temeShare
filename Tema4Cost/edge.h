#ifndef EDGE_H
#define EDGE_H

#include "node.h"

class Edge
{
public:

    Edge();
    Edge(Node f,Node s);
    Node getFirst()const;
    Node getSecond()const;
    float getCost()const;
    //void setCost();

private:

    Node m_first;
    Node m_second;
    float m_cost;

};

#endif // EDGE_H
