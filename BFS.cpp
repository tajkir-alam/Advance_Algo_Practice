#include <bits/stdc++.h>
#define inf 10000000;
using namespace std;

vector<int> AdjList[15];

int dist[15];
queue<int> Q;

void BFS(int source)
{
    for (int i = 0; i <= 9; i++)
    {
        dist[i] = inf;
    }
    dist[source] = 0;
    Q.push(source);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int j = 0; j < AdjList[u].size(); j++)
        {
            int v = AdjList[u][j];
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }

    for (int i = 0; i <= 9l; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    int numOfEdges, v, u;

    cout << "Please enter the number of edges \n";

    cin >> numOfEdges;

    cout << "Please enter the matrix \n";

    for (int i = 1; i <= numOfEdges; i++)
    {
        cin >> u >> v;

        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    int source;
    cout << "Please enter the source vertex for BFS: ";
    cin >> source;

    BFS(source);

    cout << "The adjacency List is:" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }
}


//! Demo Input
// Number of Edges = 9

// vertices:
// 0 1
// 0 4
// 1 5
// 2 3
// 2 5
// 2 6
// 5 6
// 6 7
// 3 7

// source: 1