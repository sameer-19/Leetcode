class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(auto x: nums) mp[x]++;
        int n=nums.size();
        vector<int> ans;
        for(auto x: mp)
        {
            if(x.second>(n/3)) ans.push_back(x.first);
        }
        return ans;
    }
};