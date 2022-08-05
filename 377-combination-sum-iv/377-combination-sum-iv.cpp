class Solution {
public:
    int solve(int target,vector<int> &nums,vector<int> &dp)
    {
        if(target==0) return 1;
        
        if(dp[target]!=-1) return dp[target];
        
        int ans=0;
            
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=target) ans+=solve(target-nums[i],nums,dp); 
        }
        
        return dp[target] = ans;
    }
        
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int i,j,n=nums.size();
        
        vector<unsigned int> dp(target+1,0);
        
        dp[0]=1;
        
        for(i=1;i<=target;i++)
        {
            for(j=0;j<n;j++)
            {
                if(nums[j]<=i)
                {
                    dp[i]+=dp[i-nums[j]];
                }
                else break;
            }
        }
        
        return dp[target];
    }
};