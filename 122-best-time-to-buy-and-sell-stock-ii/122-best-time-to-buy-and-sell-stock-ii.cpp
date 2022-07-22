class Solution {
public:
    int solve(int idx,int n,int buy,vector<int>&prices,vector<vector<int>> &dp)
    {
        if(idx==n) return 0;
        
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        
        int profit=0;
        
        if(buy)
        {
            int take = -prices[idx] + solve(idx+1,n,0,prices,dp);
            int notTake = 0 + solve(idx+1,n,1,prices,dp);
            profit = max(take,notTake);
        }
        else
        {
            int sell = prices[idx] + solve(idx+1,n,1,prices,dp);
            int notSell = 0 + solve(idx+1,n,0,prices,dp);
            profit = max(sell,notSell);
        }
        
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size(),i;
        
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        
        int buy=1;
        
        return solve(0,n,buy,prices,dp);
        
    }
};