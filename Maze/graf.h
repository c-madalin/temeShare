#ifndef GRAF_H
#define GRAF_H

#include "edge.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <QPoint>

class Graf
{
private:
    std::vector<Node> m_nodes;
    std::vector<Edge> m_edges;
    std::vector<std::vector<int>> m_grafMatrix;
    std::vector<std::vector<Node>> m_paths;
    std::vector<Node*> m_exits;
    Node* startNode;
public:
    Graf();
    bool addEdge(Node f, Node S);
    bool addNode(QPoint pos,int val,int type);
    void setMatrix();
    void setPaths();
    void createGraf();
    bool edgeExist(Node f, Node s);
    Node* findNode(int x, int y);
    std::vector<std::vector<Node>> bfs();
    std::vector<Node> getNodes() const {return m_nodes;}
    std::vector<Edge> getEdges() const {return m_edges;}
    std::vector<std::vector<Node>> getPaths() const {return m_paths;}
    int getStartNode()const{return startNode->getValue();}
    void setExits()
    {
        for (int i = 0; i < m_grafMatrix.size(); i++)
        {
            for (int j = 0; j < m_grafMatrix[i].size(); j++)
            {
                if(m_grafMatrix[i][j]==2)
                    m_exits.push_back(findNode(i,j));
            }
        }
    }
    void showExits()
    {
        for(auto n :m_exits)
        {std::cout<<n->getPos().y()<<" "<<n->getPos().x()<<std::endl;
        }

    }

    struct NodeHasher {
        std::size_t operator()(const Node& node) const {
            QPoint pos = node.getPos();
            size_t h1 = std::hash<int>()(pos.x());
            size_t h2 = std::hash<int>()(pos.y());
            return h1 ^ (h2 << 1);
        }
    };

    struct NodeEquals {
        bool operator()(const Node& lhs, const Node& rhs) const {
            return lhs.getPos() == rhs.getPos() && lhs.getValue() == rhs.getValue() && lhs.getType() == rhs.getType();
        }
    };
};

#endif
