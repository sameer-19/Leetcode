class Solution {
public:
    
    int jump(vector<int>& nums) {
        int i,n=nums.size(),curMax=0,mx=0,ans=0;
        
        for(i=0;i<n-1;i++)
        {
            if(i+nums[i]>mx) mx=i+nums[i];
            if(i==curMax)
            {
                ans++;
                curMax=mx;
            }
        }
        
        return ans;
    }
};