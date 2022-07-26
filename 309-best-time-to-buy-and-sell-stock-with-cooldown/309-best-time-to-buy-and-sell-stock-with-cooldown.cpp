class Solution {
public:
    
    // Memoization
    int solve(int idx,int n,int buy,vector<int>&prices,vector<vector<int>> &dp)
    {
        if(idx>=n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        
        int profit=0;
        
        if(buy)
        {
            profit = max(-prices[idx]+solve(idx+1,n,0,prices,dp),0+solve(idx+1,n,1,prices,dp));    
        }
        else
        {
            profit = max(prices[idx]+solve(idx+2,n,1,prices,dp),0+solve(idx+1,n,0,prices,dp));
        }
        // Time complexity - O(n*2), Space complexity - O(n*2 + n) (n for aux. stack space)
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int i,j;
        
        int n=prices.size();
        
        vector<vector<int>> dp(n+2,vector<int> (2,0));
        
        // Tabulation
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
        
                if(buy)
                {
                    profit = max(-prices[idx]+dp[idx+1][0],0+dp[idx+1][1]);    
                }
                else
                {
                    profit = max(prices[idx]+dp[idx+2][1],0+dp[idx+1][0]);
                }
                
                dp[idx][buy] = profit;
            }
        }
        
        return dp[0][1];
        
    }
};