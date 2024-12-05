#include "graf.h"
#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
Graf::Graf() : startNode(nullptr) {}


bool Graf::addEdge(Node f, Node s)
{
    for (const Edge& edge : m_edges) {
        if ((edge.getFirst() == f && edge.getSecond() == s) ||
            (edge.getFirst() == s && edge.getSecond() == f)) {
            return false;
        }
    }

    if(f==s)
    {
        return false;
    }

    Edge e(f,s);
    m_edges.push_back(e);
    return true;
}

bool Graf::addNode(QPoint pos,int val,int type)
{
    for (const Node& n : m_nodes) {
        if (n.getPos() == pos) {
            return false;
        }
    }

    Node n;
    n.setPos(pos);
    n.setValue(val);
    n.setType(type);
    m_nodes.push_back(n);

    return true;
}
void Graf::setMatrix()
{
    std::ifstream f("C:\\Desktop\\facultate folder\\sem3\\AG\\Maze\\mazeMatrix.txt");

    if (!f.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        perror("Error");
        return;
    } else {
        std::cout << "File deschis successfully!" << std::endl;
    }

    int n, m;
    f >> n >> m;
    if (!f) {
        std::cerr << "Error reading matrix dimensions!" << std::endl;
        return;
    }

    std::cout << "Matrix dimensions: " << n << " x " << m << std::endl;

    m_grafMatrix.resize(n, std::vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f >> m_grafMatrix[i][j];
            if (!f) {
                std::cerr << "Error reading matrix element at (" << i << ", " << j << ")" << std::endl;
                return;
            }
        }
    }

    f.close();
    std::cout << "File read successfully!" << std::endl;
}


void Graf::setPaths()
{
    m_paths=bfs();
}


void Graf::createGraf() {

    std::cout<<"s-a creat graful";
    for (int i = 0; i < m_grafMatrix.size(); i++)
    {
        for (int j = 0; j < m_grafMatrix[i].size(); j++)
        {
            if (m_grafMatrix[i][j] != 0)
            {
                QPoint p(i, j);
                addNode(p, (int)m_nodes.size() + 1, m_grafMatrix[i][j]);
                if (m_grafMatrix[i][j] == 3)
                {   startNode = &m_nodes.back();
                    std::cout<<std::endl<<"avem nod de start"<<std::endl;
                    std::cout<<startNode->getPos().y()<<" "<<startNode->getPos().x()<<std::endl;
                    std::cout<<startNode->getValue()<<std::endl;
                }

                if (m_grafMatrix[i][j] == 2)
                {m_exits.push_back(&m_nodes.back());




                    std::cout<<"avem nod de iesire"<<std::endl;}
            }
        }
    }

    for (Node &node : m_nodes) {
        QPoint pos = node.getPos();
        int x = pos.x();
        int y = pos.y();

        // Sus
        if (x > 0 && m_grafMatrix[x - 1][y] != 0) {
            Node* neighbor = findNode(x - 1, y);
            if (neighbor) addEdge(node, *neighbor);
        }

        // Jos
        if (x < m_grafMatrix.size() - 1 && m_grafMatrix[x + 1][y] != 0) {
            Node* neighbor = findNode(x + 1, y);
            if (neighbor) addEdge(node, *neighbor);
        }

        // stanga
        if (y > 0 && m_grafMatrix[x][y - 1] != 0) {
            Node* neighbor = findNode(x, y - 1);
            if (neighbor) addEdge(node, *neighbor);
        }

        // Dreapta
        if (y < m_grafMatrix[x].size() - 1 && m_grafMatrix[x][y + 1] != 0) {
            Node* neighbor = findNode(x, y + 1);
            if (neighbor) addEdge(node, *neighbor);
        }
    }
}
bool Graf::edgeExist(Node f, Node s)
{

    for (Edge& edge : m_edges)
    {
        if ((edge.getFirst() == f && edge.getSecond() == s) ||
            (edge.getFirst() == s && edge.getSecond() == f))
        {
            return true;
        }
    }
    return false;
}


Node* Graf::findNode(int x, int y) {
    for (Node& node : m_nodes) {
        if (node.getPos() == QPoint(x, y))
        {
            return &node;
        }
    }
    return nullptr;
}

std::vector<std::vector<Node>> Graf::bfs() {
    for (Node& node : m_nodes) {
        if (node.getType() == 3) {
            startNode = &node;
            break;
        }
    }

    if (!startNode) {
        std::cerr << "Nu s-a găsit nodul de start!" << std::endl;
        return {};
    }

    std::unordered_map<Node, Node*, NodeHasher, NodeEquals> parentMap;
    std::unordered_map<Node, bool, NodeHasher, NodeEquals> visited;
    std::queue<Node*> coada;

    std::vector<std::vector<Node>> exitPaths;

    coada.push(startNode);
    visited[*startNode] = true;

    while (!coada.empty()) {
        Node* currentNode = coada.front();
        coada.pop();

        if (currentNode == nullptr) continue;

        QPoint pos = currentNode->getPos();
        int x = pos.x();
        int y = pos.y();

        if (currentNode->getType() == 2) {
            std::vector<Node> path;
            Node* current = currentNode;

            while (current) {
                path.push_back(*current);
                current = parentMap[*current];
            }
            std::reverse(path.begin(), path.end());
            exitPaths.push_back(path);
            continue;
        }

        std::vector<QPoint> neighbors = {
            QPoint(x - 1, y), QPoint(x + 1, y), QPoint(x, y - 1), QPoint(x, y + 1)
    };

    for (const QPoint& neighborPos : neighbors) {
        Node* neighbor = findNode(neighborPos.x(), neighborPos.y());

        if (neighbor && !visited[*neighbor] && edgeExist(*currentNode, *neighbor)) {
            visited[*neighbor] = true;
            parentMap[*neighbor] = currentNode;
            coada.push(neighbor);
        }
    }
}

return exitPaths;
}
