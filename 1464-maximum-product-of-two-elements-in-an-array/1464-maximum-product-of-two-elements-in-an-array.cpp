class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        int mx = 0, secondMx = 0,idx = 0;
        
        for(int i=0;i<n;i++) 
        {
            if(mx<nums[i])
            {
                mx=nums[i];
                idx=i;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(idx!=i)
            {
                secondMx = max(secondMx,nums[i]);
            }
        }
        
        return (mx-1)*(secondMx-1);
        
    }
};