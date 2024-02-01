#include<iostream>
#include <list>
#include <stack>
using namespace std;

// Класс для представления графа
class Graph
{
    int V;	// Количество вершин

    //  Указатель на массив, содержащий список смежности
    list<int>* adj;

    // Функция, используемая topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);
public:
    Graph(int V);   // Конструктор

    // Функция для добавления ребра в граф
    void addEdge(int v, int w);

    // Выводит топологическую сортировку графа
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// Рекурсивная функция, используемая topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
    stack<int>& Stack)
{
    // Помечаем текущий узел как посещенный
    visited[v] = true;

    // Рекурсивно вызываем функцию для всех смежных вершин
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    // Добавляем текущую вершину в стек с результатом
    Stack.push(v);
}

// Функция для поиска топологической сортировки. 
// Рекурсивно использует topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;

    // Помечаем все вершины как непосещенные
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Вызываем рекурсивную вспомогательную функцию 
    // для поиска топологической сортировки для каждой вершины
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Выводим содержимое стека
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

// Программа для тестирования 
int main()
{
    // Создаем граф, приведенный на диаграмме выше
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}
