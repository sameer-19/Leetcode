class Solution {
public:
    bool check(int node,vector<int> adj[],bool vis[],bool dfsvis[])
    {
        vis[node]=1;
        dfsvis[node]=1;
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(check(it,adj,vis,dfsvis)) return true;
            }
            else if(dfsvis[it]) return true;
        }
        
        dfsvis[node]=0;
        
        return false;
    }
    
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        bool vis[100005]={false},dfsvis[100005]={false};
        
        vector<int> adj[100005];
        
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(check(i,adj,vis,dfsvis)) return false;
            }
        }
        return true;
    }
};