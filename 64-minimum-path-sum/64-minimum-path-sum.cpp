class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>& grid,
                                                        vector<vector<int>> &dp)
    {
        if(i<0 || i>=m || j<0 || j>=n) return 1e9;
        if(i==0 and j==0) return grid[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans;
        
        ans= min(solve(i-1,j,m,n,grid,dp),solve(i,j-1,m,n,grid,dp)) + grid[i][j];
        
        return dp[i][j]= ans;
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int i,j,m=grid.size(),n=grid[0].size();
        
        for(i=1;i<n;i++) grid[0][i]+=grid[0][i-1];
        for(i=1;i<m;i++) grid[i][0]+=grid[i-1][0];
        
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};