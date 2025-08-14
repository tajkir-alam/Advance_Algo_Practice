#include <bits/stdc++.h>
#define inf 10000000;
using namespace std;

vector<int> AdjList[15];
char Str[] = {'S', 'D', 'F', 'A', 'B', 'C', 'E', 'G'};

int dis[15];
int fin[15];
int Tim;
queue<int> Q;

void DFS(int u)
{
    ++Tim;
    dis[u] = Tim;

    for (int i = 0; i < AdjList[u].size(); i++)
    {
        int v = AdjList[u][i];
        if (dis[v] == 0)
        {
            DFS(v);
        }
    }
    ++Tim;
    fin[u] = Tim;
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
    cout << "Please enter the source vertex for DFS: ";
    cin >> source;

    DFS(source);

    for(int i = 0; i <= 7; i++){
        cout << Str[i] << ": " << dis[i] << " " << fin[i] << endl;
    }
}

//! Demo Input
// Number of Edges = 14

// vertices:
// 0 1
// 0 3
// 0 5
// 1 5
// 1 6
// 2 1
// 2 6
// 2 7
// 3 4
// 3 5
// 4 0
// 5 4
// 6 5
// 7 5

// source: 0