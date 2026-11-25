#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, edges, u, v, start;
    vector<int> graph[20];
    int visited[20] = {0};

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter two vertices: ";
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    queue<int> q;
    q.push(start);
    visited[start] = 1;

    cout << "BFS Traversal: ";

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return 0;
}
