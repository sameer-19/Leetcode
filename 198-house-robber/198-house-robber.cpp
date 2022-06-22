class Solution {
public:
    int rob(vector<int>& nums) {
        int i,dp[101],n=nums.size();
        dp[0]=nums[0];
        
        for(i=1;i<n;i++)
        {
            int pick = nums[i];
            if(i>1) pick += dp[i-2];
            
            int notPick = 0 + dp[i-1];
            
            dp[i]=max(pick,notPick);
        }
        return dp[n-1];
    }
};