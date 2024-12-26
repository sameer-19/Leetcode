class Solution {
public:
    int totalSum;
    int solve(int idx, int sum, vector<int> &nums, int &target, vector<vector<int>> &dp)
    {
        if(idx==nums.size())
        {
            if(target==sum) return 1;
            return 0;
        }
        
        if(dp[idx][totalSum+sum]!=INT_MIN) return dp[idx][totalSum+sum];
        
        int add = solve(idx+1, sum+nums[idx], nums, target, dp);
        int sub = solve(idx+1, sum-nums[idx], nums, target, dp);
        
        return dp[idx][totalSum+sum] = add + sub;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<int>> dp(n, vector<int> (2*totalSum + 1, INT_MIN));
        return solve(0,0,nums, target, dp);
    }
};