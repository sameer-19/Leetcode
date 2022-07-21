class Solution {
public:
    
    // Memoization
    int solve(int idx,int buy,int cap,vector<int>& prices,
                                vector<vector<vector<int>>> &dp)
    {
        if(idx==prices.size() || cap==0) return 0;
        
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        
        int profit=0;
        
        if(buy)
        {
            profit = max(-prices[idx]+solve(idx+1,0,cap,prices,dp), 
                                       0 + solve(idx+1,1,cap,prices,dp));
        }
        else
        {
            profit = max(prices[idx]+solve(idx+1,1,cap-1,prices,dp),
                                       0 + solve(idx+1,0,cap,prices,dp));
        }
        
        return dp[idx][buy][cap] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<vector<int>>> dp(n+1, 
                    vector<vector<int>> (2, vector<int> (k+1, 0)));
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=k;cap++)
                {
                    int profit=0;
        
                    if(buy)
                    {
            profit = max(-prices[idx]+dp[idx+1][0][cap],0 + dp[idx+1][1][cap]);
                    }
                    else
                    { 
            profit=max(prices[idx]+dp[idx+1][1][cap-1], 0 + dp[idx+1][0][cap]); 
                    }
                    
                    dp[idx][buy][cap]=profit;
                }
            }
        }
        
        return dp[0][1][k];
    }
};