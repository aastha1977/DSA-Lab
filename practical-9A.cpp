#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
};

Edge edges[100];
int parent[20];

int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

int main()
{
    int n, m;
    int totalCost = 0, count = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cout << "Enter u, v and weight: ";
        cin >> edges[i].u >> edges[i].v
            >> edges[i].weight;
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(edges, edges + m,
         [](Edge a, Edge b)
         {
             return a.weight < b.weight;
         });

    cout << "Edges in MST:\n";

    for (int i = 0; i < m; i++)
    {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b)
        {
            parent[a] = b;

            cout << edges[i].u << " - "
                 << edges[i].v << " : "
                 << edges[i].weight << endl;

            totalCost += edges[i].weight;
            count++;
        }
    }

    if (count != n - 1)
        cout << "Graph is disconnected; MST not possible.\n";
    else
        cout << "Minimum Cost = " << totalCost << endl;

    return 0;
}