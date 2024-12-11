#include "node.h"

Node::Node()
    :m_value(0){}

Node::Node(int val, QPoint pos)
    :m_value(val),m_pos(pos)
{

}

int Node::getValue() const
{
    return m_value;
}

QPoint Node::getPos() const
{
    return m_pos;
}

bool Node::operator==(const Node &other) const
{
    return m_value==other.m_value && m_pos== other.m_pos;
}

void Node::setPos(QPoint pos)
{
    m_pos=pos;
}
