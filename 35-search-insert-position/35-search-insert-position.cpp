class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,ans=-1;
        if(target<nums[0]) return 0;
        if(target>nums[nums.size()-1]) return nums.size();
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r=mid-1;
            else
            {
                ans=mid;
                l=mid+1;
            }
        }
        if(ans==-1) return 1;
        else return ans+1;
    }
};