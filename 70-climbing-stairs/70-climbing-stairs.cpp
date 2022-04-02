class Solution {
public:
    int climbStairs(int n) {
        long long dp[50]={0},i;
        dp[1]=1;dp[2]=2;
        for(i=3;i<50;i++) dp[i]+=dp[i-1]+dp[i-2];
        return dp[n];
    }
};