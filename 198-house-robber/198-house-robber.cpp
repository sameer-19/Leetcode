class Solution
{
    public:
        int solve(int idx, vector<int> &nums, vector<int> &dp)
        {
            if (idx < 0) return 0;

            if (dp[idx] != -1) return dp[idx];

            int take = nums[idx] + solve(idx - 2, nums, dp);

            int notTake = solve(idx - 1, nums, dp);

            return dp[idx] = max(take, notTake);
        }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, 0);
        
        for(int idx=0;idx<n;idx++)
        {
            int take = nums[idx] + (idx-2>=0 ? dp[idx - 2] : 0);

            int notTake = (idx-1>=0 ? dp[idx - 1] : 0);

            dp[idx] = max(take, notTake);
        }
        
        return dp[n-1];
        // return solve(n - 1, nums, dp);
    }
};