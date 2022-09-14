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
    
    int robber1(vector<int> &nums)
    {
        int n=nums.size();
        vector<int> dp(n+2);
        
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n-1;i++)
        {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        
        return dp[n-2];
    }
    
    int robber2(vector<int> &nums)
    {
        int n=nums.size();
        vector<int> dp(n+2);
        
        dp[1]=nums[1];
        dp[2]=max(nums[1],nums[2]);
        
        for(int i=3;i<n;i++)
        {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
//         vector<vector<int>> dp(n,vector<int> (2,-1));
        
//         ans=max(solve(n-1,0,nums,dp),solve(n-2,1,nums,dp));
        
        ans=max(robber1(nums),robber2(nums));
        
        return ans;
    }
};