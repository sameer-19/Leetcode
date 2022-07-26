class Solution {
public:
    
    int solve(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        
        if(i==0 || j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        
        ans+= solve(i-1,j,m,n,dp);
        ans+=solve(i,j-1,m,n,dp);
        
        return dp[i][j] = ans;
    }
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        
        return solve(m-1,n-1,m,n,dp);
    }
};