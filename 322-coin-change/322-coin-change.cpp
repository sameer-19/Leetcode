class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        
        int n=coins.size();
        
        int i,j,dp[amount+1];
        
        for(i=0;i<=amount;i++) dp[i]=amount+1;
        
        dp[0]=0;
        
        for(i=0;i<n;i++)
        {
            for(j=1;j<=amount;j++)
            {
                if(coins[i]<=j)   
                    dp[j] = min(dp[j],dp[j-coins[i]]+1);
            }
        }
        
        return dp[amount]>amount ? -1 : dp[amount];
    }
};