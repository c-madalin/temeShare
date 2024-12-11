#ifndef GRAF_H
#define GRAF_H

#include "edge.h"
#include "node.h"

#include <vector>
#include <unordered_map>

class Graf
{
public:
    Graf();
    Graf(const Graf& other);
    std::vector<Node>& getNodes();
    std::vector<Edge>& getEdges();

    bool addNode(QPoint pos);
    bool addEdge(Node f,Node s);

    void updateMatrixSize();
    void updateMatrixContent(int line,int col);
    void writeMatrix();

public:
    std::vector<Edge> getGenericTree();
    std::vector<Edge> getKruskalTree();

private:
    std::vector<Node> m_nodes;
    std::vector<Edge> m_edges;
    std::vector<Node> m_topo;
    std::vector<std::vector<int>> m_matrix;
    std::vector<std::vector<int>> m_adiacent;
};

#endif // GRAF_H


