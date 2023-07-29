class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> ans(n,1);
        
        int curProduct = 1;
        
        for(int i=n-2;i>=0;i--)
        {
            curProduct*=nums[i+1];
            ans[i]=curProduct;
        }
        
        curProduct=1;
        
        for(int i=1;i<n;i++)
        {
            curProduct*=nums[i-1];
            ans[i]*=curProduct;
        }
        
        return ans;
    }
};