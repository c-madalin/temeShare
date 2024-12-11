#include "graf.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <QDebug>
#include <QMessageBox>
#include <algorithm>
#include <numeric>
#include <vector>


Graf::Graf() {}

Graf::Graf(const Graf &other): m_nodes(other.m_nodes),
    m_edges(other.m_edges)
{

}

std::vector<Node>& Graf::getNodes()
{
	return m_nodes;
}

std::vector<Edge>& Graf::getEdges()
{
	return m_edges;
}

bool Graf::addNode(QPoint pos)
{
	const int overlapThreshold = 40;
	for (const auto& node : m_nodes)
	{
		int dx = node.getPos().x() - pos.x();
		int dy = node.getPos().y() - pos.y();

		int distance = (dx * dx) + (dy * dy);

		if ((int)std::sqrt(distance) < overlapThreshold)
		{
			return false;
		}
	}
	Node n((int)getNodes().size(), pos);
	m_nodes.push_back(n);

	updateMatrixSize();
	return true;

}

bool Graf::addEdge(Node f, Node s)
{
	if (f == s)
		return false;

	for (Edge& edge : m_edges)
	{
		if (edge.getFirst() == f && edge.getSecond() == s)
		{
			return false;
		}
	}
	Edge e(f, s);
	m_edges.push_back(e);
	updateMatrixContent(f.getValue(), s.getValue());
	return true;
}

void Graf::updateMatrixSize()
{
	m_matrix.push_back(std::vector<int>(m_nodes.size(), 0));
	for (auto& row : m_matrix) {
		row.push_back(0);
	}
    m_adiacent.push_back(std::vector<int>());
    writeMatrix();
}

void Graf::updateMatrixContent(int line, int col)
{
	if (line < m_nodes.size() && col < m_nodes.size()) {
		m_matrix[line][col] = 1;
        m_adiacent[line].push_back(col);
    }
	else {
		qDebug() << "Indici invalizi pentru matrice.";
	}
	writeMatrix();
}


void Graf::writeMatrix()
{
    std::ofstream g("C:/Desktop/facultate folder/sem3/AG/Tema4Cost/matrix.txt");

	if (!g.is_open()) {
		throw std::ios_base::failure("Nu s-a putut deschide fisierul pentru scriere.");
	}

    for (int i = 0; i < m_matrix.size(); i++)
    {
        for (int j = 0; j < m_matrix[i].size(); j++)
        {
            g << m_matrix[i][j] << " ";
        }
        g << std::endl;
    }
	g.close();

}
///////////////////////////////////

int findParent(std::vector<int>& parent, int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent, parent[node]);
    }
    return parent[node];
}
void unionSets(std::vector<int>& parent, std::vector<int>& rank, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}
std::vector<Edge> Graf::getKruskalTree() {
    std::vector<Edge> mst; // Arborele parțial minim rezultat
    std::vector<int> parent(m_nodes.size());
    std::vector<int> rank(m_nodes.size(), 0);

    // Inițializare DSU
    std::iota(parent.begin(), parent.end(), 0);

    // Sortare muchii după cost
    std::sort(m_edges.begin(), m_edges.end(), [](const Edge& a, const Edge& b) {
        return a.getCost() < b.getCost();
    });

    for (const auto& edge : m_edges) {
        int u = edge.getFirst().getValue();
        int v = edge.getSecond().getValue();

        // Adaugă muchia doar dacă nu formează un ciclu
        if (findParent(parent, u) != findParent(parent, v)) {
            mst.push_back(edge);
            unionSets(parent, rank, u, v);
        }
    }

    return mst;
}
std::vector<Edge> Graf::getGenericTree() {
    std::vector<Edge> mst; // Arborele rezultat
    std::vector<bool> inMST(m_nodes.size(), false);
    std::vector<float> minCost(m_nodes.size(), std::numeric_limits<float>::max());
    std::vector<int> parent(m_nodes.size(), -1);

    minCost[0] = 0; // Pornim de la primul nod

    for (int i = 0; i < m_nodes.size() - 1; ++i) {
        float minEdgeCost = std::numeric_limits<float>::max();
        int u = -1;

        // Găsește nodul cu cost minim, care nu este în MST
        for (int v = 0; v < m_nodes.size(); ++v) {
            if (!inMST[v] && minCost[v] < minEdgeCost) {
                minEdgeCost = minCost[v];
                u = v;
            }
        }

        if (u == -1) break; // Dacă nu mai există noduri, ieșim

        inMST[u] = true;

        // Actualizează costurile pentru nodurile adiacente
        for (int v = 0; v < m_nodes.size(); ++v) {
            if (!inMST[v] && m_matrix[u][v] > 0) {
                float weight = m_matrix[u][v];
                if (weight < minCost[v]) {
                    minCost[v] = weight;
                    parent[v] = u;
                }
            }
        }
    }

    // Construiește MST din vectorul de părinți
    for (int v = 1; v < m_nodes.size(); ++v) {
        if (parent[v] != -1) {
            Edge edge(m_nodes[parent[v]], m_nodes[v]);
            mst.push_back(edge);
        }
    }

    return mst;
}

// std::vector<Edge> Graf::getKruskalTree()
// {
//     std::vector<Edge> treeEdges; // Muchiile arborelui rezultat
//     std::vector<Edge> edges = m_edges; // Copiem muchiile grafului
//     std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
//         return a.getCost() < b.getCost();
//     });

//     // Structură Union-Find pentru detectarea ciclurilor
//     std::vector<int> parent(m_nodes.size());
//     std::vector<int> rank(m_nodes.size(), 0);

//     // Inițializare Union-Find
//     for (int i = 0; i < parent.size(); ++i)
//         parent[i] = i;

//     // Funcții helper pentru Union-Find
//     auto find = [&](int node) -> int {
//         if (parent[node] != node)
//             parent[node] = find(parent[node]);
//         return parent[node];
//     };

//     auto unionSet = [&](int node1, int node2) {
//         int root1 = find(node1);
//         int root2 = find(node2);

//         if (root1 != root2)
//         {
//             if (rank[root1] > rank[root2])
//                 parent[root2] = root1;
//             else if (rank[root1] < rank[root2])
//                 parent[root1] = root2;
//             else
//             {
//                 parent[root2] = root1;
//                 rank[root1]++;
//             }
//         }
//     };

//     // Construim arborele minim
//     for (const Edge& edge : edges)
//     {
//         int u = edge.getFirst().getValue();
//         int v = edge.getSecond().getValue();

//         if (find(u) != find(v))
//         {
//             treeEdges.push_back(edge); // Adăugăm muchia în arbore
//             unionSet(u, v);
//         }

//         // Terminăm când avem (n-1) muchii
//         if (treeEdges.size() == m_nodes.size() - 1)
//             break;
//     }

//     return treeEdges;
// }
// std::vector<Edge> Graf::getGenericTree()
// {
//     std::vector<Edge> treeEdges; // Muchiile arborelui rezultat
//     std::unordered_set<int> visited; // Noduri vizitate
//     std::stack<int> stack; // Stivă pentru DFS

//     if (m_nodes.empty())
//         return treeEdges;

//     stack.push(0); // Începem de la nodul 0
//     visited.insert(0);

//     while (!stack.empty())
//     {
//         int current = stack.top();
//         stack.pop();

//         for (int neighbor : m_adiacent[current])
//         {
//             if (visited.find(neighbor) == visited.end())
//             {
//                 // Adaugă muchia în arbore
//                 treeEdges.emplace_back(m_nodes[current], m_nodes[neighbor]);

//                 // Marchează nodul ca vizitat
//                 visited.insert(neighbor);
//                 stack.push(neighbor);
//             }
//         }
//     }

//     return treeEdges;
// }



