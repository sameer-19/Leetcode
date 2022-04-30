class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx=-1,n=nums.size(),idx=0;
        for(int i=0;i<n;i++)
        {
            if(mx<nums[i])
            {
                idx=i;
                mx=nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return 0;
        if(nums[n-1]>=2*nums[n-2]) return idx;
        return -1;
    }
};