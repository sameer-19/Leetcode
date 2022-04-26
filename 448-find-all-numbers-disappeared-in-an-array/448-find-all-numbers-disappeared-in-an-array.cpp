class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i;
        int n=nums.size();
        
        for(i=0;i<n;i++)
        {
            int m=abs(nums[i])-1;
            nums[m]= (nums[m]>0) ? -nums[m] : nums[m];
        }
        vector<int> ans;
        
        for(i=0;i<n;i++)
        {
            if(nums[i]>0) ans.push_back(i+1);
        }
        return ans;
    }
};