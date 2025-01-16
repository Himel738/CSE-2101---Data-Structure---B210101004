 #include<bits/stdc++.h>
 using namespace std;
 
 class graph
 {
    vector<vector<int>> adj;

    public:
    graph(int vertices)
    {
        adj.resize(vertices);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print()
    {
        for(int i = 0; i < adj.size(); i++)
        {
            cout << "Vertex " << i << ":";

            for(int j = 0; j < adj[i].size(); j++)
            {
                cout << "-> " << adj[i][j];
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

    int a,b,c;
    cout << "Enter The Number of Combination : ";
    cin >> c;
    cout << endl;

    for(int i = 0; i < c; i++)
    {
        cin >> a >> b;
       g.addEdge(a,b);
    }
    g.print();
 }