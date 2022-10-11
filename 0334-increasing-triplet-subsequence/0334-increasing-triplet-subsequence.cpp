class Solution {
public:
    /*
    Brute- Three loops  - O(n^3)
    Better - Two loops + store the maximum element (form suffix max array) -  O(n^2)
    Optimal1 - 
    
    */
    
    bool increasingTriplet(vector<int>& nums) {
        bool ans=false;
        
        int n=nums.size(),i;
        
        if(n<3) return false;
        
        int prefixMin[n],suffixMax[n];
        
        prefixMin[0]=nums[0];
        suffixMax[n-1]=nums[n-1];
        
        for(i=1;i<n;i++)
        {
            prefixMin[i]=min(prefixMin[i-1],nums[i]);
        }
        
        for(i=n-2;i>=0;i--)
        {
            suffixMax[i]=max(suffixMax[i+1],nums[i]);
        }
        
        for(i=1;i<n-1;i++)
        {
            if(nums[i]>prefixMin[i-1] and nums[i]<suffixMax[i+1]) return true;
        }
        
        return false;
    }
};