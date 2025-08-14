#include <bits/stdc++.h>
using namespace std;

int mat[15][15];
vector<int> AdjList[15];

int main()
{
    int numOfEdges, v, u;

    memset(mat, 0, sizeof(mat));

    cout << "Please enter the number of edges \n";

    cin >> numOfEdges;

    cout << "Please enter the matrix";

    for (int i = 1; i <= numOfEdges; i++)
    {   
        cin >> u >> v;

        mat[u][v] = 1;
        mat[v][u] = 1;

        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    cout << "The adjacency matrix is:" << endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << "The adjacency List is:" << endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < AdjList[i].size(); j++){
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }
}