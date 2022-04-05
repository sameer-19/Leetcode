class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int > mp;
        int i,j;
        for(i=0;i<nums.size();i++) mp[nums[i]]=i+1;
        for(i=0;i<nums.size();i++)
        {
            int left=target-nums[i];
            if(mp[left]>0 && mp[left]!=i+1)
            {
                return {i,mp[left]-1};
            }
        }
        return {0,1};
    }
};