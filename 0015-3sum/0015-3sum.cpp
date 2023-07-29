class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>> ans;
        
        if(n<3) return ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            int target = -nums[i];
            
            if(i>0)
            {
                if(nums[i]==nums[i-1]) continue;
            }
            
            int left=i+1,right=n-1;
            
            while(left<right)
            {
                int sum=nums[left]+nums[right];
                if(sum==target)
                {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    while(left<right and nums[left-1]==nums[left]) left++;
                    right--;
                    while(left<right and nums[right+1]==nums[right]) right--;
                }
                else if(sum<target)
                {
                    left++;
                }
                else right--;
            }
        }
        
        return ans;
    }
};