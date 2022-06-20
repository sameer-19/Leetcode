class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1) return nums[0];
        
        int i,ans=INT_MAX;
        
        int left=0,right=n-1;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            ans=min(ans,nums[mid]);
            
            if(nums[mid]>nums[left] and nums[mid]>nums[right])
            {
                left=mid+1;
            }
            else if(nums[mid]>nums[left] and nums[mid]<nums[right])
            {
                right=mid-1;
            }
            else if(nums[mid]<nums[left] and nums[mid]<nums[right])
            {
                right=mid-1;
            }
            else 
            {
                left=mid+1;
            }
            
        }
        
        return ans;
    }
};