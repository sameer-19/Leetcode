class Solution {
public:
    int solve(int idx,int prev,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(idx==nums.size())
        {
            return 0;
        }
        
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        
        int notTake = solve(idx+1,prev,nums,dp);
        int take = 0;
        if(prev==-1 || nums[idx]>nums[prev]) take = 1 + solve(idx+1,idx,nums,dp);
        
        
        return dp[idx][prev+1] = max(take,notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1) return 1;
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
                
        return solve(0,-1,nums,dp);
        
    }
};