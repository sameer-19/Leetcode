class Solution {
public:
    bool dfs(int src,int dest,vector<int> adj[],vector<bool> &visited)
    {
        if(src==dest) 
        {
            visited[dest] = true;
            return true;
        }
        
        visited[src] = true;
        
        for(auto x: adj[src])
        {
            if(!visited[x])
            {
                if(dfs(x,dest,adj,visited)) return true;
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n,false);
        
        if(dfs(source,destination,adj,visited)) return true;
        
        return false;
    }
};