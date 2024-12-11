class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans = 1, n = nums.size();
        sort(nums.begin(),nums.end());
        
        int i=0, j=1;
        
        while(j<n)
        {
            if(nums[j]-nums[i]>2*k)
            {
                ans = max(ans, j-i);
                while(i<=j and nums[j]-nums[i]>2*k)
                {
                    i++;
                }
            }
            j++;
        }
        
        ans = max(ans, j-i);
        
        return ans;
    }
};