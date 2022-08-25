class Solution {
public:
    bool checkCycle(int node,vector<int> adj[],
                            vector<bool> &visited,vector<bool> &dfsvisited)
    {
        visited[node]=true;
        dfsvisited[node]=true;
        
        for(auto child: adj[node])
        {
            if(!visited[child])
            {
                if(checkCycle(child,adj,visited,dfsvisited)) return true;
            }
            else if(dfsvisited[child]) return true;
        }
        
        dfsvisited[node]=false; 
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> adj[n];
        
        int i,j,m=a.size();
        
        for(i=0;i<m;i++){
            adj[a[i][1]].push_back(a[i][0]);
        }
        
        vector<bool> visited(n,false),dfsvisited(n,false); 
        
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(checkCycle(i,adj,visited,dfsvisited)) return false;
            }
        }
        
        return true;
    }
};