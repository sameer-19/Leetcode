class Solution {
public:
    int solve(int m,int n,string a,string b,vector<vector<int>> &dp)
    {
        if(m==0 || n==0) 
        {
            return 0;
        }
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(a[m-1]==b[n-1]) return dp[m][n] = 1+solve(m-1,n-1,a,b,dp);
        return dp[m][n] = max(solve(m-1,n,a,b,dp),solve(m,n-1,a,b,dp));
    }
    
    int longestCommonSubsequence(string a, string b) {
        int m=a.length(),n=b.length(),i,j;
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[m][n];
    }
};