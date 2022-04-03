class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,ans=nums[0];
        for(int i=0;i<size(nums);i++)
        {
            sum+=nums[i];
            if(sum>ans) ans=sum;
            if(sum<0) sum=0;
            // sum=max(nums[i],sum+nums[i]);
            // ans=max(ans,sum);
        }
        return ans;
    }
};