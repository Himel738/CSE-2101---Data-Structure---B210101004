
class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    int start = 0,level = 0;
	    vector<int> visited(V,-1);
	    
	    queue<int> g;
	    g.push(start);
	    visited[start] = level;
	    
	    while(!g.empty())
	    {
	        int a = g.front();
	        g.pop();
	        
	        for(auto it : adj[a])
	        {
	            if(visited[it] < 0)
	            {
	                g.push(it);
	                visited[it] = visited[a] + 1;
	            }
	        }
	        
	        if(visited[X] >= 0)
	        {
	            return visited[X];
	        }
	 
	    }
	    
	    return - 1;
	}
};