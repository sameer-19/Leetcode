class Solution {
public:
    int partitions(vector<int>&nums,int maxSum) // minimum partitions required
    {
        int sum=0,splits=0;
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]<=maxSum)
            {
                sum+=nums[i];
            }
            else
            {
                splits++;
                sum=nums[i];
            }
        }
        return splits+1;
    }
    
    
    int splitArray(vector<int>& nums, int m) {
        int sum=0,n=nums.size(),i,maxElement=INT_MIN;
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            maxElement=max(maxElement,nums[i]);
        }
        int left=maxElement,right=sum;
        
        int ans=sum;
        while(left<=right)
        {
            int maxSumAllowed=left+(right-left)/2;
            
            if(partitions(nums,maxSumAllowed)<=m) 
            {
                right=maxSumAllowed-1;
                ans=maxSumAllowed;
            }
            else left=maxSumAllowed+1;
        }
        
        return ans;
    }
};