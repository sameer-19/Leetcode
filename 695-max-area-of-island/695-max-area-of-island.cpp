class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int m,int n,
              vector<vector<bool>> &visited)
    {
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(grid[i][j]==0) return 0;
        if(visited[i][j]==true) return 0;
        
        visited[i][j]=true;
        
        int ans=1;
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];
            
            ans+=solve(grid,x,y,m,n,visited);
        }
        
        return ans;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0,i,j;
        
        int m=grid.size(),n=grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool> (n,false));
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]==1 and visited[i][j]==false)
                {
                    int size = solve(grid,i,j,m,n,visited);
                    
                    ans=max(ans,size);
                }
            }
        }
        
        return ans;
    }
};