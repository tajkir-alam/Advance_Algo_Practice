#include<bits/stdc++.h>
using namespace std;
/// Adjacency List, G
vector<int>G[10];

vector<int>GT[10];
int st[10];
int ft[10];
int tim;
int node,edge;

void DFS(int u)
{
    /// increase tim
    ++tim;
    /// set start time for u --> st[]
    st[u]=tim;
    /// for each adjacent node of u, we will try to visit there
    /// So, for each adjacent node,
    for(int i=0;i<G[u].size();i++)
    {
        /// The adjacent node is v
        int v=G[u][i];
        ///if not discovered yet ( observing start time)
        if(st[v]==0)
        {
        /// --> adjacent v,  call DFS(v)
            DFS(v);
        }

    }




    /******** After completing all the task ********/

    /// increase tim
    /// Set finish time ----> ft[]
    ++tim;
    ft[u]=tim;

    return ;
}

/// For GT

vector<int>compo;
void DFS2(int u)
{
    compo.push_back(u);
     /// increase tim
    ++tim;
    /// set start time for u --> st[]
    st[u]=tim;
    /// for each adjacent node of u, we will try to visit there
    /// So, for each adjacent node,
    for(int i=0;i<GT[u].size();i++)
    {
        /// The adjacent node is v
        int v=GT[u][i];
        ///if not discovered yet ( observing start time)
        if(st[v]==0)
        {
        /// --> adjacent v,  call DFS(v)
            DFS2(v);
        }

    }




    /******** After completing all the task ********/

    /// increase tim
    /// Set finish time ----> ft[]
    ++tim;
    ft[u]=tim;

}


int main()
{
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
        /// Which Means:  G er uth vector e v boshbe/ insert hobe
        G[u].push_back(v);

        /********GT*********/
        /// Process Transpose Graph
          /// v er ghore u store korte hobe
        /// Which Means:  GT er vth vectore u boshbe/ insert hobe

        GT[v].push_back(u);
    }

    /// Perform DFS: we must mention a starting node

    int startingnode=1;
    DFS(startingnode);

    /// Loop/ Iterate over all the nodes to visit them
    for(int i=1;i<=8;i++)
    {
        if(st[i]==0){DFS(i);
        cout<<"NOOOOOOOOOOOOOOOO\n";
        }
    }

    for(int i=1;i<=8;i++)
    {
        cout<<"Node Number: "<<i<<", Start Time= "<<st[i]<<" , Finish Time = "<<ft[i]<<endl;
    }


    /// We have to prepare a transpose Graph, GT
    /// This task is/will be performed during Input Processing

    /// After Performing DFS, we have to sort all the nodes based on
    /// Finish time ( Des Order)

    /*******Sorting***********/
    pair<int,int>p;  /// finish time, node number
    vector<pair<int,int> >temp;
    /// For each node, i = 1 to 10,
    for(int i=1;i<=8;i++)
    {
         /// (ft[i], i)
                 /// pp = make_pair(ft[i], i)
        /// temp vector - e push korbo pp

          pair<int,int>pp = make_pair(ft[i], i);
          temp.push_back(pp);
    }

    /// sort korbo temp vector
    sort(temp.begin(),temp.end());

    cout<<"Printing Nodes after Sorting\n";
    for(int i=0;i<temp.size();i++)
    {
        pair<int,int>p = temp[i];
        cout<<p.first<<" "<<p.second<<" "<<endl;
    }


    /********2nd Time DFS**********/
    /// As, we are asked to perform dfs based on finish time (des order)
    /// So, we will perform loop in reverse order

    /// Memory Clear
    memset(st,0,sizeof (st));
    memset(ft,0,sizeof (ft));
    cout<<"Printing Components: \n";
    for(int i=temp.size()-1;i>=0;i--)
    {
    /// for(int i=temp.size() - 1;i>=0;i--)
        /// what is in ith emement ?
        /// temp[i] --> pp = temp[i]; (20, b) ==> (20, 2)
        pair<int,int>p = temp[i];
       // cout<<p.first<<" "<<p.second<<" "<<endl;
        /// pp.first , pp.second= (x)
            /// if x is not visted for GT
            /// DFS2(x)

        int x = p.second;
        if(st[x]==0) {
            DFS2(x);
//            for(int j=0;j<compo.size();j++)cout<<compo[j]<<" ";
//            cout<<endl;
            for(int j=0;j<compo.size();j++)cout<<char('A' - 1 +compo[j])<<" ";
            cout<<endl;
            compo.clear();
        }
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
*/
