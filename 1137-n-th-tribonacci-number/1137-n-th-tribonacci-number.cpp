class Solution {
public:
    int solve(int n,vector<int> &dp)
    {
        if(n==0 || n==1) return dp[n] = n;
        if(n==2) return dp[n] = 1;
        if(dp[n]!=-1) return dp[n];
        
        return dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
    
    int tribonacci(int n) {
        vector<int> dp(n+3,-1);
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        int i;
        for(i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        
        return dp[n];
    }
};