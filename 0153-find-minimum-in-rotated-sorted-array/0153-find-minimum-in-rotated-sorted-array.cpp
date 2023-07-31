class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=min(nums[0],nums[nums.size()-1]);
        
        int low=0,high=nums.size()-1;
        
        if(nums[low]<=nums[high]) return nums[low];
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            ans=min(ans,nums[mid]);
            
            if(nums[mid]>nums[high]) low=mid+1;
            else high=mid-1;
        }
        
        return ans;
    }
};