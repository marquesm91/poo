#include "graph.h"

typedef struct Edges
{
    unsigned int i;
    unsigned int j;
    unsigned int weight;
} Edges;

int main()
{
    Edges edge0 = {0, 1, 20}; // A -> B
    Edges edge1 = {0, 3, 80}; // A -> D
    Edges edge2 = {0, 6, 90}; // A -> G
    Edges edge3 = {1, 4, 50}; // B -> E
    Edges edge4 = {1, 5, 10}; // B -> F
    Edges edge5 = {2, 5, 50}; // C -> F
    Edges edge6 = {2, 7, 20}; // C -> H
    Edges edge7 = {2, 3, 10}; // C -> D
    Edges edge8 = {3, 5, 40}; // D -> F
    Edges edge9 = {3, 6, 20}; // D -> G
    Edges edge10 = {4, 6, 30}; // E -> G

    Graph<Edges, int> g(8);

    g.insert(edge0);
    g.insert(edge1);
    g.insert(edge2);
    g.insert(edge3);
    g.insert(edge4);
    g.insert(edge5);
    g.insert(edge6);
    g.insert(edge7);
    g.insert(edge8);
    g.insert(edge9);
    g.insert(edge10);

    g.DJK(7);

    /*g.IsAllConnected()? cout << "Yes\n" : cout << "No\n";

    cout << g.ShowConnectedComponents() << endl;

    g.ForceAllConnected();

    cout << g.ShowConnectedComponents() << endl;

    g.IsAllConnected()? cout << "Yes\n" : cout << "No\n";*/

    //g.BFS(0);
    //g.DFS(0);

    return 0;
}