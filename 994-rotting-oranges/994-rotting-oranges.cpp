class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        
        int i,j,ans=0;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]==2) 
                {
                    q.push({i,j});
                }
            }
        }
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!q.empty())
        {
            int sz=q.size();
            
            for(i=0;i<sz;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                
                for(j=0;j<4;j++)
                {
                    int x=p.first+dx[j];
                    int y=p.second+dy[j];
                    if(x>=0 and x<m and y>=0 and y<n and grid[x][y]==1)
                    {
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
            if(!q.empty()) ans++;
        }
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        
        return ans;
    }
};