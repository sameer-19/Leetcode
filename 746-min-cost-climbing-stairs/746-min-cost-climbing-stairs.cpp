class Solution {
public:
    
    int solve(int idx,vector<int>&cost,vector<int> &dp)
    {
        if(idx==0) return cost[0];
        if(idx==1) return cost[1];
        if(dp[idx]!=-1) return dp[idx];
        
return dp[idx] = min(solve(idx-1,cost,dp),solve(idx-2,cost,dp)) +
                            (idx==cost.size() ? 0: cost[idx]);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size(),i;
        vector<int> dp(n+1,-1);
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(i=2;i<=n;i++)
        {
            if(i<n)
            {
                dp[i]=min(dp[i-1],dp[i-2])+cost[i];
            }
            else dp[i]=min(dp[i-1],dp[i-2]);
        }
        
        return dp[n];
    }
};