class Solution {
public:
    long solve(int n,vector<int> &nums,int target,vector<long> &dp)
    {
        if(target==0) return 1;
        
        if(dp[target]!=-1) return dp[target];
        
        long total = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=target) 
            {
                total+=solve(n,nums,target-nums[i],dp);
            }
        }
        
        return dp[target] = total;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int sum = 0, n = nums.size();
        // vector<long> dp(target+1, -1);
        // return solve(n,nums,target,dp);
        
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        
        for(int targ=1;targ<=target;targ++)
        {
            unsigned int total = 0;
        
            for(int i=0;i<n;i++)
            {
                if(nums[i]<=targ) 
                {
                    total+=dp[targ-nums[i]];
                }
            }

            dp[targ] = total;
        }
        
        return dp[target];
    }
};