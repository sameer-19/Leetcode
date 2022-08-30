class Solution {
public:
    int parent[1005];
    int rank[10005];
    
    void makeSet()
    {
        int i;
        for(i=0;i<1005;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    int findParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    void unionNodes(int u,int v)
    {
        u=findParent(u);
        v=findParent(v);
        
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else
        {
            parent[v]=u;
            rank[u]++;
        }   
    }
    
    struct node{
        int u;
        int v;
        int wt;
    };
    
    static bool cmp(node a,node b)
    {
        return a.wt<b.wt;
    }
    
    
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        makeSet();
        
        vector<node> edges;
        
        int i,j,n=points.size();
        
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({i,j,dist});
            }
        }
        
        sort(edges.begin(),edges.end(),cmp);
        
        int ans=0,cnt=n-1;
        
        for(auto [u,v,wt]: edges)
        {
            if(cnt==0) break;
            
            if(findParent(u)!=findParent(v))
            {
                ans+=wt;
                unionNodes(u,v);
                cnt--;
            }
        }
        
        return ans;
    }
};