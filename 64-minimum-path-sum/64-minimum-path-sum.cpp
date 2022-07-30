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
        int m=grid.size(),n=grid[0].size();
        
        vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
        
        return solve(m-1,n-1,m,n,grid,dp);
    }
};