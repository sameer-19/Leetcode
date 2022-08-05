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
        
        vector<bool> prev(sum+1,false),cur(sum+1,false);
        
        prev[0]=true;
        cur[0]=true;
        
        if(nums[0]<=sum) prev[nums[0]]=true;
        
        for(int idx=1;idx<n;idx++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool notTake = prev[target];
                bool take = false;
                if(nums[idx]<=target) take = prev[target-nums[idx]];

                cur[target] = take|notTake;
            }
            prev=cur;
        }
        
        return prev[sum];
    }
};