class Solution {
public:
    void dfs(int node,vector<int> adj[],stack<int> &s,vector<bool> &visited)
    {
        visited[node]=true;
        
        for(auto child: adj[node])
        {
            if(!visited[child])
            {
                dfs(child,adj,s,visited);
            }
        }
        s.push(node);
    }
    
    bool cycle(int node,vector<int> adj[],vector<bool> &visited,vector<bool> &dfsvisited)
    {
        visited[node]=true;
        dfsvisited[node]=true;
        
        for(auto child: adj[node])
        {
            if(!visited[child])
            {
                if(cycle(child,adj,visited,dfsvisited)) return true;
            }
            else if(dfsvisited[child]) return true;
        }
        
        dfsvisited[node]=false;
        return false;
    }
        
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        vector<int> ans;
        stack<int> s;
        vector<int> adj[n];
        vector<bool> visited(n,false),dfsvisited(n,false);
        
        int i,j;
        
        for(i=0;i<a.size();i++)
        {
            adj[a[i][1]].push_back(a[i][0]);    
        }
        
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(cycle(i,adj,visited,dfsvisited)) return ans;
            }
        }
        
        for(i=0;i<n;i++) visited[i]=false;
        
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,s,visited);
            }
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};