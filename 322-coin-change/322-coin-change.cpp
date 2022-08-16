class Solution {
public:
    int solve(int idx,vector<int> &coins,int amount,vector<vector<int>> &dp)
    {
        if(idx==0)
        {
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        }
        if(amount==0) return 0;
        
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        
        int take = 1e9;
        if(coins[idx]<=amount) take = 1 + solve(idx,coins,amount-coins[idx],dp);
        
        int notTake = solve(idx-1,coins,amount,dp);
        
        return dp[idx][amount] = min(take,notTake);
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(),coins.end());
        int n=coins.size(),i,j;
        
        vector<int> cur(amount+1,1e9),prev(amount+1,1e9);
        
        for(i=0;i<=amount;i++) prev[i] = (i%coins[0]==0) ? i/coins[0] : 1e9;
        cur[0]=0;
        
        for(int idx=1;idx<n;idx++)
        {
            for(int amt=1;amt<=amount;amt++)
            {
                int take = 1e9;
                if(coins[idx]<=amt) take = 1 + cur[amt-coins[idx]];

                int notTake = prev[amt];

                cur[amt] = min(take,notTake);
            }
            prev = cur;
        }
        
        // int ans = solve(n-1,coins,amount,dp);
        return (prev[amount]==(int)1e9) ? -1 : prev[amount];
        
    }
};