class Solution {
public:
    
    void dfs(int node,vector<int> adj[],vector<bool> &visited)
    {
        visited[node]=true;
        
        for(auto child: adj[node])
        {
            if(!visited[child])
            {
                dfs(child,adj,visited);
            }
        }
    }
        
    int makeConnected(int n, vector<vector<int>>& arr) {
        int sz=arr.size(),i;
        
        if(sz<n-1) return -1;
        
        vector<int> adj[1+n];
        
        for(i=0;i<sz;i++)
        {
            adj[arr[i][0]].push_back(arr[i][1]);
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        
        vector<bool> visited(n,false);
        int ans=0;
        
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans++;
                dfs(i,adj,visited);
            }
        }
        
        return ans-1;
    }
};