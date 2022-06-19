class Solution {
public:
    
    bool solve(vector<int>&nums,int th,int mid)
    {
        int n=nums.size(),i;
        
        int sum=0;
        
        for(i=0;i<n;i++)
        {
            sum+=(ceil((double)nums[i]/mid));
        }
        
        if(sum<=th) return true;
        return false;
    }
    
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=INT_MAX;
        
        int i,n=nums.size();
        
        int left=1,right=INT_MAX;
        
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            bool z = solve(nums,threshold, mid);
            
            if(z)
            {
                ans=min(ans,mid);
                right=mid-1;
            }
            else left=mid+1;
        }
        
        return ans;
    }
};