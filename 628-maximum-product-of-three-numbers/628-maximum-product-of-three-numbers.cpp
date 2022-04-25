class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        
        int mx1=INT_MIN,mx2=INT_MIN,mx3=INT_MIN,mn1=INT_MAX,mn2=INT_MAX,id1=-1,id2=-1,id3=-1,id4=-1,id5=-1;
        int i;
        
        for(i=0;i<n;i++)
        {
            if(mx1<nums[i])
            {
                mx1=nums[i];
                id1=i;
            }
        }
        
        for(i=0;i<n;i++)
        {
            if(mx2<nums[i] && i!=id1)
            {
                mx2=nums[i];
                id2=i;
            }
        }
        
        for(i=0;i<n;i++)
        {
            if(mx3<nums[i] && (i!=id1 && i!=id2))
            {
                mx3=nums[i];
                id3=i;
            }
        }
        
        for(i=0;i<n;i++)
        {
            if(mn1>nums[i] && i!=id1)
            {
                mn1=nums[i];
                id4=i;
            }
        }
        
        for(i=0;i<n;i++)
        {
            if(mn2>nums[i] && (i!=id4 && i!=id1))
            {
                mn2=nums[i];
                id5=i;
            }
        }
        
        return max(nums[id1]*nums[id2]*nums[id3], nums[id1]*nums[id4]*nums[id5]);
    }
};