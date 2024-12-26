class Solution {
public:
    void solve(int idx, int sum, vector<int> &nums, int &target, int &ans)
    {
        if(idx==nums.size())
        {
            if(target==sum) ans++;
            return;
        }
        
        solve(idx+1, sum+nums[idx], nums, target, ans);
        solve(idx+1, sum-nums[idx], nums, target, ans);
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        solve(0,0,nums, target, ans);
        
        return ans;
    }
};