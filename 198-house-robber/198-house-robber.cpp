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
        
        vector<int> dp(n+1,-1);
        
        return solve(n-1,nums,dp);       
    }
};