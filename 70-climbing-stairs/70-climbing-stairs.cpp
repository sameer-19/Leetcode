class Solution {
public:
    int solve(int i,int n,vector<int> &dp)
    {
        if(i>n) return 0;
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        
        int ans=0;
        ans += solve(i+1,n,dp);
        ans+=solve(i+2,n,dp);
        
        return dp[i] = ans;
    }
    
    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int> dp(n+1,-1);
        
        return solve(0,n,dp);
    }
};