 #include<bits/stdc++.h>
 using namespace std;
 
 class graph
 {
    vector<vector<pair<int,int>>> adj;

    public:
    graph(int vertices)
    {
        adj.resize(vertices);
    }

    void addEdge(int u, int v,int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    void print()
    {
        for(int i = 0; i < adj.size(); i++)
        {
            cout << "Vertex " << i << ":";

            for(auto edge: adj[i])
            {
                cout << "-> (" << edge.first << "," << edge.second << ")";
            }

            cout << endl;
        }
    }


 };

 int main ()
 {
    int v;
    cout << "Enter The Number of Vertices : ";
    cin >> v;
    cout << endl;

    graph g(v);

    int a,b,c,w;
    cout << "Enter The Number of Combination : ";
    cin >> c;
    cout << endl;

    for(int i = 0; i < c; i++)
    {
        cin >> a >> b >> w;
       g.addEdge(a,b,w);
    }
    g.print();
 }