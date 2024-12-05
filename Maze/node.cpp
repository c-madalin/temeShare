#include "node.h"

Node::Node() {}

void Node::setValue(int val)
{
    m_value=val;
}

void Node::setPos(QPoint p)
{
    m_pos=p;
}

void Node::setType(int type)
{
    m_type=type;
}

QPoint Node::getPos() const
{
    return m_pos;
}

int Node::getValue() const
{
    return m_value;
}

int Node::getType() const
{
    return m_type;
}

bool Node::operator==(const Node &other) const
{
    return m_pos == other.m_pos && m_value == other.m_value && m_type==other.m_type;
}

Node &Node::operator=(const Node &node)
{
    if(this == &node)
        return *this;
    this->m_pos = node.m_pos;
    this->m_value = node.m_value;
    this->m_type=node.m_type;
    return *this;
}

Node::Node(QPoint pozition, int value, int type):
    m_pos{pozition},m_value{value},m_type{type} {}






