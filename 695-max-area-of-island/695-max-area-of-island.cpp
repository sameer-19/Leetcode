class Solution {
public:
    int dfs(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<bool>> &visited)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0) return 0;
        
        if(visited[i][j]) return 0;
        
        visited[i][j]=1;
        
        int ans=1;
        
        ans+= dfs(i+1,j,m,n,grid,visited); // down
        ans+= dfs(i-1,j,m,n,grid,visited); // up 
        ans+= dfs(i,j+1,m,n,grid,visited); // right
        ans+= dfs(i,j-1,m,n,grid,visited); // left
        
        return ans;
    }
        
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        
        int i,j,ans=0;
        
        vector<vector<bool>> visited(m+1,vector<bool> (n+1,false));
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]==1 and visited[i][j]==false)
                {
                    ans=max(ans,dfs(i,j,m,n,grid,visited));
                }
            }
        }
        
        return ans;
    }
};