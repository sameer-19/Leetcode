class Solution {
public:
    int solve(int idx,int flag,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(idx<0) return 0;
        
        if(idx==0)
        {
            if(flag==0) return 0;
        }
        
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        
        int take = nums[idx]+solve(idx-2,flag,nums,dp);
        int notTake = solve(idx-1,flag,nums,dp);
        
        return dp[idx][flag] = max(take,notTake);
    }
    
    int rob(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        if(n==1) return nums[0];
        
        vector<vector<int>> dp(n,vector<int> (2,-1));
        
        ans=max(solve(n-1,0,nums,dp),solve(n-2,1,nums,dp));
        
        return ans;
    }
};