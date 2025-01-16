#include<bits/stdc++.h>
using namespace std;

vector<int> BFS_traverse(vector<vector<int>> graph,int start)
{
    int size = graph.size();
    vector<bool>visited(size,false);
    vector<int> bfs_traverse;

    queue <int> g;
    g.push(start);
    visited[start] = true;

    while(!g.empty())
    {
        int a = g.front();
        g.pop();
        bfs_traverse.push_back(a);

        for(auto it : graph[a])
        {
            if(!visited[it])
            {
                g.push(it);
                visited[it] = true;
            }
        }
    }

    return bfs_traverse;

}

int main ()
{
    cout << "Enter The Number of Vertices- ";
    int vertices;
    cin >> vertices;
    cout << endl;

    cout << "Enter The Number of Combination- ";
    int combination;
    cin >> combination;
    cout << endl;

    vector<vector<int>> graph(vertices);

    for(int i = 0; i < combination; i++)
    {
        int u,v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

     vector<int> traverse = BFS_traverse(graph,0);

     for(auto it : traverse)
     {
        cout << it << endl;
     }


}