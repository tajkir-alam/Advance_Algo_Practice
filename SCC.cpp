    #include <bits/stdc++.h>
    using namespace std;

    // Adjacency List
    vector<int> g[10];
    vector<int> gt[10];
    int st[10]; // Start time
    int ft[10]; // Finish time
    int tim;
    //  (finish time vs node number) pair & then sort
    vector<pair<int, int>> fp; // finish pair

    void dfs(int u)
    {
        st[u] = ++tim;

        // try to visit all the adjacent of u

        for (int i = 0; i < g[u].size(); i++)
        {
            // lets assume i'th adjacent of u is v
            int v = g[u][i];

            // if v is not visited yet
            if (st[v] == 0)
            {
                dfs(v);
            }
        }
        ft[u] = ++tim;
    }

    void dfs2(int u)
    {
        cout << char(u + 'a' - 1) << " ";
        st[u] = ++tim;

        // try to visit all the adjacent of u

        for (int i = 0; i < gt[u].size(); i++)
        {
            // lets assume i'th adjacent of u is v
            int v = gt[u][i];

            // if v is not visited yet
            if (st[v] == 0)
            {
                dfs2(v);
            }
        }
        ft[u] = ++tim;
    }

    int main()
    {
        int node, edge;
        cout << "please enter node and edge \n";
        cin >> node >> edge;

        cout << "please ender the characters directions \n";
        for (int i = 0; i < edge; i++)
        {
            char ch1, ch2;
            cin >> ch1 >> ch2;

            // a  1, b = 2, c =3;
            // e.g, ch1 = e, ch2 = a;
            // u = e - a + 1 =5;
            // v = a - a + 1 = 1;

            int u = ch1 - 'a' + 1;
            int v = ch2 - 'a' + 1;

            // Prepare Adjacency List
            // e: a ['e' er bucket a 'a' add hobe.]
            g[u].push_back(v);

            // Prepare transpose graph
            gt[v].push_back(u);
        }
        //* SCC Perfrom
        /* step 1: Perform DFS
            For every node, which is yet to be visited we will perform DFS */
        for (int i = 1; i <= node; i++)
        {
            // if i is not visited
            // if st[i] = 0, then it is not visited yet.
            if (st[i] == 0)
            {
                dfs(i);
            }
        }

        // Now test / examine all the start time and finish time of each node

        cout << "\n here is the output: \n";
        for (int i = 1; i <= node; i++)
        {
            cout << char('a' + i - 1) << ": " << st[i] << " " << ft[i] << endl;
        }

        // Prepare pairs for nodes vs their finish time
        for (int i = 1; i <= node; i++)
        {
            pair<int, int> p = make_pair(ft[i], i);
            fp.push_back(p);
        }
        // Sort finish pair acsending order
        sort(fp.begin(), fp.end());

        // reverse the pair || in decsending order
        reverse(fp.begin(), fp.end());

        // print all the nodes based on their finish time (decsending order)

        for (int i = 0; i < fp.size(); i++)
        {
            // i'th node name, the finish time of i'th node
            cout << fp[i].second << " " << fp[i].first << endl;
        }

        // step 3:
        // Perform dfs on gt,
        // order: fp -> decreasing order
        // we already prepared that order in previous state

        // Now we need to perform dfs on gt

        // Now er need to clear all the memory
        memset(st, 0, sizeof st);
        memset(ft, 0, sizeof ft);
        tim = 0;

        int k = 0;
        cout << "============================\n";
        for (int i = 0; i < fp.size(); i++)
        {
            // node number1
            int u = fp[i].second;
            if (st[u] == 0)
            {
                ++k;
                cout << "Component " << k << ": ";
                dfs2(u);
                cout << endl;
            }
        }

        return 0;
    }

    // * ------------------------------------------------------------
    /*
    ! node , edge
    8 14

    directions:
    a b
    b c
    b e
    b f
    c d
    c g
    d c
    d h
    e a
    e f
    f g
    g h
    g f
    h h
    */

    //* Code from sir.
    /* #include <bits/stdc++.h>
    using namespace std;
    /// Adjacency List
    vector<int> g[10];
    vector<int> gt[10];
    int st[10]; /// Start time
    int ft[10]; /// Finish Time
    int tim;
    /// (finish time vs node number) pair
    vector<pair<int, int>> fp; /// finish pair
    /// Then sort

    void dfs(int u)
    {

        st[u] = ++tim;

        /// try to visit all the adjacent of u

        for (int i = 0; i < g[u].size(); i++)
        {
            /// lets assume ith adjacent of u is v
            int v = g[u][i];
            /// If v is not visited yet
            if (st[v] == 0)
                dfs(v);
        }
        ft[u] = ++tim;
    }

    void dfs2(int u)
    {
        cout << char(u + 'a' - 1) << " ";
        st[u] = ++tim;

        /// try to visit all the adjacent of u

        for (int i = 0; i < gt[u].size(); i++)
        {
            /// lets assume ith adjacent of u is v
            int v = gt[u][i];
            /// If v is not visited yet
            if (st[v] == 0)
                dfs2(v);
        }
        ft[u] = ++tim;
    }

    int main()
    {
        int node = 8, edge = 14;
        //    cin>>node>>edge;

        for (int i = 0; i < edge; i++)
        {
            char ch1, ch2;
            cin >> ch1 >> ch2;
            /// a = 1, b = 2, c=3
            /// ch1 = e ch2 = a;
            /// u =  e -a + 1 = 5
            /// v = a - a + 1 = 1
            int u = ch1 - 'a' + 1;
            int v = ch2 - 'a' + 1;

            /// Adjacency List prepare
            /// e: a
            g[u].push_back(v);
            /// Prepare transpose graph
            gt[v].push_back(u);
        }
        /// SCC
        /// Step 1: peform dfs
        /// For every node, which is yet to be visited
        /// We will perform dfs

        for (int i = 1; i <= node; i++)
        {
            /// if i is not visited
            /// if st[i]=0, then it is not visited yet
            if (st[i] == 0)
                dfs(i);
        }

        /// Not test/examine the start time and finish time of each node

        for (int i = 1; i <= node; i++)
        {
            /// 1 to a conversion
            cout << char('a' + i - 1) << " : " << st[i] << " " << ft[i] << endl;
        }

        /// parepare pairs for nodes vs their finish time

        /// Step 2:
        for (int i = 1; i <= node; i++)
        {
            pair<int, int> p = make_pair(ft[i], i);
            fp.push_back(p);
        }
        /// Sort finish pair
        sort(fp.begin(), fp.end());

        /// reverse -> change order
        reverse(fp.begin(), fp.end());

        /// print all the nodes based on their finish time (des order)

        for (int i = 0; i < fp.size(); i++)
        {
            /// ith node name, the finish time of ith node
            cout << fp[i].second << " " << fp[i].first << endl;
        }
        /// step 3;
        /// perform dfs on gt ,
        /// order: fp -> decreasing order
        /// We already prepared that order in previous step

        /// Now we need to perform dfs on gt

        /// now we need to clear all the memory
        memset(st, 0, sizeof st);
        memset(ft, 0, sizeof ft);
        tim = 0;

        int k = 0;
        cout << "===============\n";
        for (int i = 0; i < fp.size(); i++)
        {
            /// node number
            int u = fp[i].second;
            if (st[u] == 0)
            {
                ++k;
                cout << "Component " << k << ": ";
                dfs2(u);
                cout << endl;
            }
        }

        return 0;
    }
    */