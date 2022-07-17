class Solution {
public:
    
    int solve(int idx,vector<int>& nums,int flag,vector<vector<int>>& dp)
    {
        if(idx<0) return 0;
        if(idx==0) return (flag==1) ? 0 : nums[idx];
        
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        
    int ans= max(solve(idx-2,nums,flag,dp)+nums[idx],solve(idx-1,nums,flag,dp));
        
        return dp[idx][flag] = ans;
    }
    
    int rob(vector<int>& nums) {
        int flag=1,n=nums.size();
        if(n==1) return nums[0];
        
        vector<vector<int>> dp(n+1, vector<int> (3,-1));
        
        return max(solve(n-1,nums,flag,dp),solve(n-2,nums,0,dp));
    }
};