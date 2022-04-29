class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size(),i=0;
        vector<int> ans(n);
        for(auto x: nums)
        {
            if(x%2==0) ans[i++]=x;
        }
        for(auto x: nums)
        {
            if(x%2!=0) ans[i++]=x;
        }
        return ans;
    }
};