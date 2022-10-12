class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size(),ans=0;
        
        for(int i=n-1;i>=2;i--)
        {
            int sum = nums[i-1]+nums[i-2];
            
            int target = nums[i];
            
            if(sum>target)
            {
                ans = sum+nums[i];
                break;
            }
        }
        
        return ans;
    }
};