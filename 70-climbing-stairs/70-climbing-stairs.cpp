class Solution {
public:
    
    // Memoization
    int solve(int i,int n,vector<int> &dp)
    {
        if(i==0) return 1;
        if(i==1) return 2;
        if(dp[i]!=-1) return dp[i];
        
        int ans=0;
        ans += solve(i-1,n,dp);
        ans += solve(i-2,n,dp);
        
        return dp[i] = ans;
    }
    
    int climbStairs(int n) {
        if(n==1 || n==2) return n;
        int prev = 1, cur=2;
//         vector<int> dp(n+1,-1);
        
//         return solve(n-1,n,dp);
        
        for(int i=3;i<=n;i++)
        {
            int tmp = prev+cur;
            prev=cur;
            cur=tmp;
        }
        
        return cur;
    }
};