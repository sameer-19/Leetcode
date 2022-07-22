class Solution {
public:
    
    // Memoization
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
    
    int tabulation(vector<int>& prices)
    {
        int n=prices.size(),i;
        
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        
        // Tabulation
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
        
                if(buy)
                {
                    int take = -prices[idx] + dp[idx+1][0];
                    int notTake = 0 + dp[idx+1][1];
                    profit = max(take,notTake);
                }
                else
                {
                    int sell = prices[idx] + dp[idx+1][1];
                    int notSell = 0 + dp[idx+1][0];
                    profit = max(sell,notSell);
                }
                
                dp[idx][buy] = profit;
            }
        }
        
        
        return dp[0][1];
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size(),i;
        
        vector<int> after(2,0),cur(2,0);
        
        // int buy=1;
        
        // Tabulation
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
        
                if(buy)
                {
                    int take = -prices[idx] + after[0];
                    int notTake = 0 + after[1];
                    profit = max(take,notTake);
                }
                else
                {
                    int sell = prices[idx] + after[1];
                    int notSell = 0 + after[0];
                    profit = max(sell,notSell);
                }
                
                cur[buy] = profit;
            }
            after = cur; 
        }
        
        
        return after[1];
        
    }
};