#include<bits/stdc++.h>
using namespace std;

vector<int>bfs(vector<vector<int>>adj,int start)
{
    int n = adj.size();
    vector<bool>visit(n,false);
    vector<int> bfsTraverse;

    queue<int> q;
    q.push(start);
    visit[start] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        bfsTraverse.push_back(u);

        for(int it: adj[u])
        {
            if(!visit[it])
            {
                q.push(it);
                visit[it] = true;
            }
        }
    }

    return bfsTraverse;

}

int main ()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    for(int i = 0; i < n; i++ )
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> order = bfs(adj,1);
    for(auto it:order)
    {
        cout << it << " ";
    }
}