#include<bits/stdc++.h>
using namespace std;
 vector<int> DFS_traverse(int start , vector<vector<int>> graph, vector<bool> &visited,vector<int>&traverse)
 {
    visited[start] = true;
    traverse.push_back(start);

    for(auto it : graph[start])
    {
        if( !visited[it])
        {
            DFS_traverse(it,graph,visited,traverse);
        }
    }
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
     vector<bool>visited(vertices,false);
     vector<int> traverse;
     DFS_traverse(0, graph,visited,traverse);

     for(auto it : traverse)
     {
        cout << it << endl;
     }


}