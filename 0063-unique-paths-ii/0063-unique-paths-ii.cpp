class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp)
    {
        if(i==1 and j==1) return 1;
        if(i==0 || j==0) return 0;
         
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(grid[i-1][j-1]==1) return dp[i][j] = 0;
        
        int left = solve(i,j-1,grid,dp);
        int top = solve(i-1,j,grid,dp);
        
        return dp[i][j] = left+top;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;         
        
        return solve(n,m,grid,dp);
    }
};