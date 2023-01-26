class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int ans=INT_MAX;
        
        vector<vector<int>> adj[n+1];
        
        for(int i=0;i<flights.size();i++)
        {
            vector<int> p = flights[i];
            adj[p[0]].push_back({p[1],p[2]});
        }
        
        // node,steps,cost
        queue<vector<int>> q;
        
        vector<int> visited(n+1,INT_MAX);
        
        q.push({src,k,0});
        visited[src] = 0;
        
        while(!q.empty())
        {
            vector<int> p = q.front();
            q.pop();
            
            int curNode = p[0], stepsLeft = p[1], cost = p[2];
            
            if(curNode==dst)
            {
                ans=min(ans,cost);
            }
            else
            {
                if(stepsLeft>0)
                {
                    for(auto x: adj[curNode])
                    {
                        if(visited[x[0]]==INT_MAX || visited[x[0]]>(cost+x[1]))
                        {
                            visited[x[0]] = cost + x[1];
                            q.push({x[0],stepsLeft-1,cost+x[1]});
                        }
                    }
                }
                else 
                {
                    for(auto x: adj[curNode])
                    {
                        if(x[0]==dst)
                        {
                            ans=min(ans,cost+x[1]);
                            break;
                        }
                    }
                }
            }
        }
        
        return ans==INT_MAX ? -1 : ans;
    }
};