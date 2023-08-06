class Solution {
public:
    
    // Recursion to DP-Memoization
    int solve(int n,vector<int> &dp)
    {
        if(n<=1) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=solve(i-1,dp)*solve(n-i,dp);
        }
        
        return dp[n] = ans;
    }
    
    int numTrees(int n) {
        // equal to catalan number
        vector<int> dp(n+1,0);
        
        dp[0] = dp[1] = 1;
        
        for(int i=1;i<=n;i++)
        {
            int ans=0;
            for(int j=1;j<=i;j++)
            {
                ans+=dp[j-1]*dp[i-j];
            }
            dp[i] = ans;
        }
        
        return dp[n];
        // return solve(n,dp);
    }
};