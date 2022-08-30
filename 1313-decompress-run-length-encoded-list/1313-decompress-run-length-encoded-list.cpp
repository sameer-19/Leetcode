class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        
        int i,j,n=nums.size();
        
        for(i=0;i<n;i+=2)
        {
            for(j=0;j<nums[i];j++)
            {
                ans.push_back(nums[i+1]);
            }
        }
        
        return ans;
    }
};