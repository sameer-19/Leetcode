class Solution {
public:
    int solve(int idx,int &n,int buy,int &fee,vector<int>&prices,vector<vector<int>> &dp)
    {
        if(idx==n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        
        int profit=0;
        
        if(buy)
        {
            profit = max(-prices[idx]+solve(idx+1,n,0,fee,prices,dp),0+solve(idx+1,n,1,fee,prices,dp));
        }
        else
        {
            profit = max(prices[idx]-fee+solve(idx+1,n,1,fee,prices,dp),0+solve(idx+1,n,0,fee,prices,dp));
        }
        
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        
        return solve(0,n,1,fee,prices,dp);
    }
};