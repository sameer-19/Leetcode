class Solution {
public:
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
    
        return solve(n,cost,dp);
    }
};