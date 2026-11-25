#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, edges, u, v, start;
    vector<int> friends[20];
    int visited[20] = {0};

    cout << "Enter number of users: ";
    cin >> n;

    cout << "Enter number of friendships: ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter two user IDs: ";
        cin >> u >> v;

        friends[u].push_back(v);
        friends[v].push_back(u);
    }

    cout << "Enter starting user: ";
    cin >> start;

    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();

        cout << "Level " << level << ": ";

        for (int i = 0; i < size; i++)
        {
            int user = q.front();
            q.pop();

            cout << user << " ";

            for (int f : friends[user])
            {
                if (!visited[f])
                {
                    visited[f] = 1;
                    q.push(f);
                }
            }
        }

        cout << endl;
        level++;
    }

    return 0;
}