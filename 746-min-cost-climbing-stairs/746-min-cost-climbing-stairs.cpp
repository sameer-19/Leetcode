class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // bottom up approach
        int dp[cost.size()+1],i,n=cost.size();
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(i=2;i<=n;i++)
        {
            dp[i]=min(dp[i-1],dp[i-2])+(i==n ? 0 : cost[i]);
        }
        return dp[n];
        // // Top down Approach
        // int index=cost.size();
        // int memo[1001]={0};
        // int z=solve(cost,index,memo);
        // return z;
    }
};