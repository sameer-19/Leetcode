class Solution {
public:
    int maxArea(vector<int>& height) {
        int lmax=0,rmax=0;
        
        int n=height.size(),ans=0;
        
        int left=0,right=n-1;
        
        while(left<right)
        {
            lmax=max(lmax,height[left]);
            rmax=max(rmax,height[right]);
            
            int mnBar = min(lmax,rmax);
            
            int curSum = (right-left)* mnBar;
            
            ans=max(ans,curSum);
            
            if(mnBar==lmax) left++;
            else right--;
        }
        
        return ans;
    }
};