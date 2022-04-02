class Solution {
public:
    int solve(vector<int> cost,int index,int memo[])
    {
        if(index==0) return cost[0];
        if(index==1) return cost[1];
        if(memo[index]!=0) return memo[index];
        return memo[index]=min(solve(cost,index-1,memo),solve(cost,index-2,memo))+(index==cost.size() ? 0 : cost[index]);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // Top down Approach
        int index=cost.size();
        int memo[1001]={0};
        int z=solve(cost,index,memo);
        return z;
    }
};