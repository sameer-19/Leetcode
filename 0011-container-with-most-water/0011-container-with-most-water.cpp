class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        
        int n=height.size();
        
        int left=0,right=n-1;
        
        while(left<=right)
        {
            int cur = min(height[left],height[right]);
            cur*=(right-left);
            ans=max(ans,cur);
            if(height[left]<=height[right]) left++;
            else right--;
        }
        
        return ans;
    }
};