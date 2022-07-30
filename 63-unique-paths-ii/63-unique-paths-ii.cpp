class Solution {
public:
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
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        
        return solve(m-1,n-1,m,n,grid,dp);
    }
};