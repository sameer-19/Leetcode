class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>> mp;
        
        int i,n=nums.size();
        
        for(i=0;i<n;i++) mp[nums[i]].push_back(i);
        
        for(i=0;i<n;i++)
        {
            int left=target-nums[i];
            
            if(left!=nums[i])
            {
                if(mp[left].size()>0)
                {
                    return {i,mp[left][0]};
                }
            }else{
                if(mp[nums[i]].size()>1)
                {
                    return {mp[nums[i]][0],mp[nums[i]][1]};
                }
            }
        }
        return {0,1};
    }
};