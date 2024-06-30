#include<bits/stdc++.h>
using namespace std;

void dfsTraverse(int start,vector<bool>&vis,vector<vector<int>>&adj,vector<int>&dfsTra)
{
    vis[start] = true;
    dfsTra.push_back(start);

    for(auto it : adj[start])
    {
        if(!vis[it])
        {
            dfsTraverse(it,vis,adj,dfsTra);
        }
    }
}

vector<int>dfs(vector<vector<int>>adj,int start)
{
   int n = adj.size();
   vector<bool> vis(n,false);
   vector<int>dfsTra;
   dfsTraverse(start,vis,adj,dfsTra);

   return dfsTra;
}
int main ()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);

    for(int i =0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> himel = dfs(adj,1);

    for(auto it: himel)
    {
        cout << it << " ";
    }
}