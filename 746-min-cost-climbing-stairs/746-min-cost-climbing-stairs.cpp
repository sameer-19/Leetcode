class Solution {
public:
    // Memoization
    int solve(int idx,vector<int>&cost,vector<int> &dp)
    {
        if(idx==0) return cost[0];
        if(idx==1) return cost[1];
        
        if(dp[idx]!=-1) return dp[idx];
        
        int ans=0;
        
ans+=min(solve(idx-1,cost,dp),solve(idx-2,cost,dp)) + (idx==cost.size()?0:cost[idx]);
     
        return dp[idx] = ans;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        vector<int> dp(n+1,-1);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2;i<=n;i++)
        {
            dp[i] = min(dp[i-1],dp[i-2]) + (i==n ? 0 : cost[i]);
        }
        
        return dp[n];
    }
};