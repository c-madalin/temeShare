#include "edge.h"
#include <cmath>

Edge::Edge() {}

Edge::Edge(Node f, Node s)
    :m_first(f),m_second(s)
{
    float dx = m_first.getPos().x() - m_second.getPos().x();
    float dy = m_first.getPos().y() - m_second.getPos().y();
    m_cost = std::sqrt(dx * dx + dy * dy);
}

Node Edge::getFirst() const
{
    return m_first;
}

Node Edge::getSecond() const
{
    return m_second;
}

float Edge::getCost() const
{
    return m_cost;
}


