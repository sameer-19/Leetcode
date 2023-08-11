class Solution {
public:
    int solve(int idx,int amount,vector<int> &coins,vector<vector<int>> &dp)
    {
        if(amount==0) return 1;
        if(idx==coins.size()) return 0;
        
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        
        int take = 0;
        if(coins[idx]<=amount) take = solve(idx,amount-coins[idx],coins,dp);
        
        int notTake = solve(idx+1,amount,coins,dp);
        
        return dp[idx][amount] = take+notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        // vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        // return solve(0,amount,coins,dp);
        
        vector<vector<int>> dp(n+1,vector<int> (amount+1,0));
        
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int i=1;i<=amount;i++) dp[n][i] = 0;
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int j=1;j<=amount;j++)
            {
                int take = 0;
                if(coins[idx]<=j) take = dp[idx][j-coins[idx]];

                int notTake = dp[idx+1][j];
                
                dp[idx][j] = take+notTake;
            }
        }
        
        return dp[0][amount];
    }
};