class Solution {
public:
    bool f(int idx,int target,vector<int>&nums,vector<vector<int>> &dp)
    {
        if(target==0) return true;
        if(idx==0) return (nums[0]==target);
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        bool notTake = f(idx-1,target,nums,dp);
        bool take = false;
        if(nums[idx]<=target) take = f(idx-1,target-nums[idx],nums,dp);
        
        return dp[idx][target] = take|notTake;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size(),i,j;
        
        for(i=0;i<n;i++) sum+=nums[i];
        
        if(sum%2!=0) return false;
        sum/=2;
        
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        
        return f(n-1,sum,nums,dp);
    }
};