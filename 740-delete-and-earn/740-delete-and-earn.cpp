class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i,n=nums.size(),dp[10005]={0},freq[10005]={0};
        for(i=0;i<n;i++) freq[nums[i]]++;
        
        dp[1]=freq[1];
        dp[2]=freq[2]*2;
        
        for(i=2;i<10005;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+(freq[i]*i));
        }
        return dp[10004];
    }
};