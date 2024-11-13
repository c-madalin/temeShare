#ifndef NODE_H
#define NODE_H
#include <QPoint>
#include <unordered_map>

class Node
{
private:

    QPoint m_pos;
    int m_value;
    int m_type;

public:
    Node();
    Node(const Node& other) {
        m_pos = other.m_pos;
        m_value = other.m_value;
        m_type = other.m_type;
    }
    void setValue(int val);
    void setPos(QPoint p);
    void setType(int type);

    QPoint getPos()const;
    int getValue()const;
    int getType()const;

    bool operator==(const Node& other)const;
    Node& operator=(const Node& node);
    Node(QPoint pozition,int value, int type);



};

#endif // NODE_H
