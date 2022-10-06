class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0;
        int n=nums.size();
        
        
        int ans=INT_MAX,sum=0;
        
        while(right<n)
        {
            sum+=nums[right];
            if(sum>=target)
            {
                ans=min(ans,right-left+1);
                while(left<=right and sum>=target)
                {
                    ans=min(ans,right-left+1);
                    sum-=nums[left];
                    left++;
                }
                right++;
            }
            else
            {
                right++;
            }
        }
        
        while(left<=right and sum>=target)
        {
            ans=min(ans,right-left+1);
            sum-=nums[left];
            left++;
        }
        
        return ans==INT_MAX ? 0 : ans;
    }
};