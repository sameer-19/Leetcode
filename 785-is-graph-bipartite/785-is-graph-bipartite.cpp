class Solution {
public:
    
    bool bipartiteDFS(int node,vector<int> adj[],vector<int> &color)
    {
        if(color[node]==-1) color[node]=1;
        
        for(auto child: adj[node])
        {
            if(color[child]==-1)
            {
                color[child]=1-color[node];
                if(!bipartiteDFS(child,adj,color)) return false;
            }
            else if(color[child]==color[node]) return false;
        }
        
        return true;
    }
    
    bool checkBipartite(vector<int> adj[],int n)
    {
        int i;
        
        vector<int> color(n,-1);
        
        for(i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!bipartiteDFS(i,adj,color)) return false;
            }
        }
        
        // for(i=0;i<n;i++)
        // {
        //     if(color[i]==-1)
        //     {
        //         if(!bipartiteBFS(i,adj,color)) return false;
        //     }
        // }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        // graph is bipartite if it does not contain odd length cycle
        int n=graph.size(),i,j;
        
        vector<int> adj[n];
        
        set<pair<int,int>> s;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<graph[i].size();j++)
            {
                if(i<graph[i][j])
                {
                    s.insert({i,graph[i][j]});
                }
                else
                {
                    s.insert({graph[i][j],i});
                }
            }
        }
        
        for(auto x: s)
        {
            adj[x.first].push_back(x.second);
            adj[x.second].push_back(x.first);
        }
        
        return checkBipartite(adj,n);
    }
};