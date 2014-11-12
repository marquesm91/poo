#ifndef GRAPH_H
#define GRAPH_H

#include "queue.h"
#include "stack.h"
#include <limits> /* For Dijkstra's Algorithm*/

template<class T, typename A>
class Graph
{
    int **matrix;
    int total_vertex;
    int total_edges;
    int Infinity;
    bool *vertex_used;

public:
    Graph(int);
    ~Graph();
    bool edge(int, int);
    bool insert(const T &);
    bool remove(const T &);
    bool IsAllConnected();
    int ShowEdges();
    int ShowVerteces();
    int ShowConnectedComponents();
    void DJK(int); /* Dijkstra's Algorithm */
    int DFS(int); /* Depth First Search */
    void BFS(int); /* Breadth First Search */
    void ForceAllConnected();
};

template<class T, typename A>
Graph<T, A>::Graph(int num_verteces)
{
    /* Inicialize some important atributes*/
    total_vertex = num_verteces;
    total_edges = 0;
    Infinity = std::numeric_limits<int>::max();

    /* Allocate space for all the lists of adjacents*/
    matrix = new int *[total_vertex];
    for (int i = 0; i < total_vertex; i++)
    {
        matrix[i] = new int[total_vertex];
    }

    /* Allocate sapce for bool vector*/
    vertex_used = new bool[total_vertex];

    /* Inicialize with 0's  and falses' */
    for (int i = 0; i < total_vertex; i++)
        for (int j = 0; j < total_vertex; j++)
            matrix[i][j] = 0;

    for (int i = 0; i < total_vertex; i++)
        vertex_used[i] = false;

}

template<class T, typename A>
Graph<T, A>::~Graph()
{
    /* Destroying the matrix */
    for (int i = 0; i < total_vertex; ++i)
        delete [] matrix[i];
    delete [] matrix;

    /* Destroying the bool vector */
    delete[] vertex_used;

}

template<class T, typename A>
bool Graph<T, A>::IsAllConnected()
{
    return (DFS(total_vertex - 1) == total_vertex);
}

template<class T, typename A>
void Graph<T, A>::ForceAllConnected()
{
    for (int i = 0; i < total_vertex; ++i)
        for (int j = 0; j < total_vertex; ++j)
            if (i != j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
}

template<class T, typename A>
int Graph<T, A>::ShowEdges()
{
    return total_edges;
}

template<class T, typename A>
int Graph<T, A>::ShowVerteces()
{
    return total_vertex;
}

template<class T, typename A>
bool Graph<T, A>::edge(int i, int j)
{
    if (matrix[i][j] >= 1)
        return true;
    else
        return false;
}

template<class T, typename A>
bool Graph<T, A>::insert(const T &edges)
{
    if (edge(edges.i, edges.j))
        return false;
    else
    {
        matrix[edges.i][edges.j] = matrix[edges.j][edges.i] = 1;
        total_edges++;
    }

    return true;
}

template<class T, typename A>
bool Graph<T, A>::remove(const T &edges)
{
    if (!edge(edges.i, edges.j))
        return false;
    else
    {
        matrix[edges.i][edges.j] = matrix[edges.j][edges.i] = 0;
        total_edges--;
    }

    return true;
}

template<class T, typename A>
int Graph<T, A>::ShowConnectedComponents()
{
    int numcomponents = 0;

    for (int i = 0; i < total_vertex; i++)
        vertex_used[i] = false;

    for (int i = 0; i < total_vertex; i++)
    {
        if (!vertex_used[i])
        {
            if (DFS(i) > 1)
                numcomponents++;
        }
    }

    return numcomponents;
}

template<class T, typename A>
void Graph<T, A>::BFS(int vertex)
{
    Queue<int> Q;

    bool *explored = new bool[total_vertex];

    /* Initailized all vertices as unexplored */
    for (int i = 1; i <= total_vertex; i++)
        explored[i] = false;

    /* Enqueue the first vertex and mark as explored */
    Q.Enqueue(vertex);
    explored[vertex] = true;

    cout << "Breadth First Search (BFS) starting from vertex " << vertex << " : ";

    while (!Q.IsEmpty())
    {
        /* Every loop Dequeue a vertex*/
        int v = Q.Dequeue();
        cout << v << " ";

        /* When have a edge, mark as explored when possible then enqueue the vertex*/
        for (int w = 1; w <= total_vertex; w++)
        {
            if (edge(v, w) && !explored[w])
            {
                Q.Enqueue(w);
                explored[w] = true;
            }
        }
    }

    cout << endl;
    delete [] explored;
}

template<class T, typename A>
int Graph<T, A>::DFS(int vertex)
{

    Stack<int> S;

    /* min recieve a "infite" value (each vertex never reach total_vertex) */
    int min = total_vertex;
    int v = vertex;
    int verteces_connected;

    bool *visited = new bool[total_vertex];

    for (int i = 0; i < total_vertex; i++)
        visited[i] = false;

    cout << "Depth First Search (DFS) starting from vertex " << vertex << " : ";

    /* Push first vertex for the stack and mark as visited*/
    S.Push(v);
    visited[v] = true;
    vertex_used[v] = true;
    verteces_connected = 1;
    cout << v << " ";

    while (!S.IsEmpty())
    {
        /* choose the min value that vertex is connected */
        for (int w = 0; w < total_vertex; w++)
        {
            if (edge(v, w) && !visited[w] && w < min)
                min = w;
        }

        /* if found a minimum value mark push to stack and mark as visited */
        if (min != total_vertex)
        {
            S.Push(min);
            visited[min] = true;
            vertex_used[min] = true;
            verteces_connected++;
            cout << min << " ";

            v = min;
            min = total_vertex;
        }
        else /* case of not found a minimium value, we have to pop first vertex of stack*/
        {
            v = S.Pop();
        }

    }
    cout << endl;
    delete [] visited;

    return verteces_connected;
}

template<class T, typename A>
void Graph<T, A>::DJK(int source)
{

    int *dist = new int[total_vertex];     // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool *sptSet = new bool[total_vertex]; // sptSet[i] will true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < total_vertex; i++)
        dist[i] = Infinity, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < total_vertex - 1; count++)
    {

        int min = Infinity, min_index;
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.

        for (int v = 0; v < total_vertex; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;


        int u = min_index;

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < total_vertex; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && matrix[u][v] && dist[u] != Infinity && dist[u] + matrix[u][v] < dist[v])
            {
                dist[v] = dist[u] + matrix[u][v];
            }
    }

    // print the constructed distance array
    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < total_vertex; i++)
        cout << i << "\t\t" << dist[i] << endl;

    delete[] sptSet;
    delete[] dist;
}

#endif