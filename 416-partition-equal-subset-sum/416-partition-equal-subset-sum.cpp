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
        
        if(sum%2!=0 || n==1) return false;
        sum/=2;
        
        vector<vector<bool>> dp(n+1,vector<bool> (sum+1,false));
        
        for(i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=sum) dp[0][nums[0]]=true;
        
        for(int idx=1;idx<n;idx++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool notTake = dp[idx-1][target];
                bool take = false;
                if(nums[idx]<=target) take = dp[idx-1][target-nums[idx]];

                dp[idx][target] = take|notTake;
            }
        }
        
        return dp[n-1][sum];
    }
};