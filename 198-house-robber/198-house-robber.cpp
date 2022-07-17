class Solution {
public:
    // Memoization
    int solve(int idx,vector<int>&nums,vector<int>&dp)
    {
        if(idx<0) return 0;
        if(idx==0) return nums[idx];
        
        if(dp[idx]!=-1) return dp[idx];
        
        int ans=0;
        
        ans = max(solve(idx-2,nums,dp)+nums[idx],solve(idx-1,nums,dp));
        
        return dp[idx] = ans;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        
        vector<int> dp(n+2,-1);
        
        dp[0]=nums[0];
        
        for(int i=1;i<=n;i++)
        {
            if(i>1) dp[i] = max(dp[i-1],dp[i-2] + (i==n ? 0 : nums[i]));
            else dp[i] = max(dp[i-1],nums[i]);
        }
        
        return dp[n-1];       
    }
};