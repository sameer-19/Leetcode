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
        
        vector<vector<int>> after(2, vector<int> (k+1,0));
        vector<vector<int>> cur(2, vector<int> (k+1,0));
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=k;cap++)
                {
                    int profit=0;
        
                    if(buy)
                    {
            profit = max(-prices[idx]+after[0][cap],0 + after[1][cap]);
                    }
                    else
                    { 
            profit=max(prices[idx]+after[1][cap-1], 0 + after[0][cap]); 
                    }
                    
                    cur[buy][cap]=profit;
                }
            }
            after = cur;
        }
        
        return after[1][k];
        /*
            Time Complexity - O(n*2*k)
            Space Complexity - O(2*k)
        */
        
    }
};