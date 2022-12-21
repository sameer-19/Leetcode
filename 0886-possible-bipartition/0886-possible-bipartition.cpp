class Solution {
public:
    vector<int> color;
    
    bool bfs(int start,int n,vector<int> adj[])
    {
        queue<int> q;
        q.push(start);
        color[start]=0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto x: adj[node])
            {
                if(color[x]==-1)
                {
                    q.push(x);
                    color[x]=1-color[node];
                }
                else if(color[x]==color[node])
                {
                    return true;
                }
            }       
        }
        
        return false;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        
        for(auto x: dislikes)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        for(int i=0;i<=n;i++) color.push_back(-1);
        
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(bfs(i,n,adj)) return false;
            }
        }
        
        return true;
    }
};