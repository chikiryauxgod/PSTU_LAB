#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
    }

    void topologicalSortUtil(int v, vector<bool>& visited, vector<int>& order) {
        visited[v] = true;

        for (int u : adjacencyList[v]) {
            if (!visited[u]) {
                topologicalSortUtil(u, visited, order);
            }
        }

        order.push_back(v);
    }

    void topologicalSort() {
        vector<bool> visited(vertices, false);
        vector<int> order;

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, order);
            }
        }

        // ѕереворачиваем пор€док, чтобы получить топологическую сортировку
        reverse(order.begin(), order.end());

        // ¬ыводим топологический пор€док
        cout << "“опологический пор€док: ";
        for (int u : order) {
            cout << u << " ";
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
