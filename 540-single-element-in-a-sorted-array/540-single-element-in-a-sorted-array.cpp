class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(),i,j;
        
        if(n==1) return nums[0];
        
        int l=0,r=n-1;
        int ans=0;
        
        if(nums[1]!=nums[0]) return nums[0];
        else if(nums[n-2]!=nums[n-1]) return nums[n-1];
        
        while(l<=r)
        {
            int mid = l+ (r-l)/2;
            
            if(nums[mid]!=nums[mid+1] and nums[mid]!=nums[mid-1]) return nums[mid];
            
        if((mid%2==0 and nums[mid]==nums[mid+1]) || (mid%2==1 and nums[mid]==nums[mid-1]))
            l=mid+1;
        else r=mid-1;
            
        }
        
        return 1;
    }
};