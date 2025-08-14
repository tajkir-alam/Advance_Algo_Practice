/// Articulation Points
#include<bits/stdc++.h>
using namespace std;
/// Adjacency List, G
vector<int>G[10];

int st[10];
int ft[10];
int low[10];
int arti[10];
int tim;
int node,edge;
vector<pair<int,int> >bridge;
int root=1; /// startingnode
int rootflag = 1;
void DFS(int u, int par)
{
    /// increase tim
    ++tim;
    /// set start time for u --> st[] ,
    /// Initially, starttime is equals to the low value
    st[u] = low[u] = tim;
    /// for each adjacent node we will try to visit there

    for(int i=0;i<G[u].size();i++)
    {
    /// So, for each adjacent node,
        int v=G[u][i];
        ///if not discovered yet ( observing start time)
        /// --> adjacent v,  call DFS(v)
        /// if v is the parent of u, then we have skip it.
        if(v==par)continue;
        if(v==root)rootflag=false;
         if(st[v]==0)
         {
                DFS(v, u);
         }

         /// the node v is already discovered.
         /// Check whether v gets disconnected if we remove u .
         /// If satisfied, then u is an articulation point
         /// The edge (u,v) is a bridge.

        low[u] = min(low[u],low[v]);
        if(low[v]>st[u])/// Then u is an articulation point
        {
            arti[u]=true;
                /// u,v pair prepare
                /// bridge->> push this pair
        }
    }

    /******** After completing all the task ********/

    /// increase tim
    tim++;
    /// Set finish time ----> ft[]
    ft[u]=tim;
    return ;
}


int main()
{
    /// Graph Input
    cin>>node>>edge;
    for(int i=1;i<=edge;i++)
    {
        /// A B ---> 1 2
        /// there is an edge from u to v
        char U, V;
        int u,v;
        cin>>U>>V;
        u = (U-'A'+1);
        v = (V-'A'+1);
        cout<<u<< " "<<v<<endl;
        /**********G*********/
        /// Now we can say, there is an edge from u to v
        /// u er ghore v store korte hobe
        /// Which Means:  G er uth vectore v boshbe/ insert hobe
        G[u].push_back(v);
        G[v].push_back(u);

    }


    root = 1;
    DFS(root,root);

    for(int i=1;i<=7;i++)
    {
        if(i==root && rootflag==1)arti[rootflag]=1;

        cout<<char('A'+i-1)<<" is ";
        if(!arti[i])cout<<"not ";
        cout<<"a articulation point\n";
    }

    return 0;

}
/*
/// Input: node/vertex , edges
followed by list of edges
8 14
A C
B A
B D
C B
C D
C E
D F
E F
E G
F D
F H
G E
G H
H H

7 9
A B
A E
A F
B C
B E
B F
C D
C E
D G

6 5
A B
A C
A D
A E
D F

*/
Md. Rakib Mia
Nahida Akter
Hazrat Anas Tazim
