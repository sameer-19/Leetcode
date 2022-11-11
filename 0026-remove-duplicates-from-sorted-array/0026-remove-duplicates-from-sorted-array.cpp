class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        
        int ans=0;
        int left=0,right=1;
        
        while(right<n)
        {
            ans++;
            while(right<n and nums[left]==nums[right]) right++;
            left++;
            if(right<n) nums[left]=nums[right];
        }
        
        return ans==0 ? 1 : ans;
    }
};