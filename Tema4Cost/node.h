#ifndef NODE_H
#define NODE_H

#include <QPoint>
class Node
{
public:
    Node();
    Node(int val,QPoint pos);
    int getValue()const;
    QPoint getPos()const;
    bool operator==(const Node& other)const;
    void setPos(QPoint pos);

private:
    int m_value;
    QPoint m_pos;

};


#endif // NODE_H
