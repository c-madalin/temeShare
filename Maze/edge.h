#ifndef EDGE_H
#define EDGE_H

#include <memory>
#include "node.h"
class Edge
{

private:
    Node m_first;
    Node m_second;
public:

    Edge(Node first_node,Node second_node);
    Edge(const Edge& edge) = default;
    Edge& operator=(const Edge& edge) = default;

    Node getFirst() const {return m_first;}
    Node getSecond() const {return m_second;}
};
#endif // EDGE_H
