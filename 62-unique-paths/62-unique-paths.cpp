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
        
        vector<vector<int>> dp(m,vector<int> (n,0));
        
        int i,j;
        
        for(i=0;i<m;i++) dp[i][0]=1;
        for(j=0;j<n;j++) dp[0][j]=1;
        
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};