class Solution {
public:
    // Memoization
    int solve(int i,int j,int m,int n,vector<vector<int>> &grid,
                                                        vector<vector<int>> &dp)
    {
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(grid[i][j]==1) return 0;
        
        if(i==0 && j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        
        ans+=solve(i-1,j,m,n,grid,dp);
        ans+=solve(i,j-1,m,n,grid,dp);
        
        return dp[i][j] = ans;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),i,j;
        if(grid[m-1][n-1]==1 || grid[0][0]==1) return 0;
        
        grid[0][0]=1;
        
        for(i=1;i<n;i++) grid[0][i]=(grid[0][i]==0 ? grid[0][i-1] : 0);
        for(i=1;i<m;i++) grid[i][0]=(grid[i][0]==0 ? grid[i-1][0] : 0);
        
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if(grid[i][j]==1) grid[i][j]=0;
                else
                {
                    grid[i][j]=grid[i-1][j]+grid[i][j-1];
                }
            }
        }
        
        return grid[m-1][n-1];
    }
};