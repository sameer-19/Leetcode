class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        map<int,vector<int>> mp;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        
        for(auto x: mp)
        {
            int first = x.first;
            int second = target - first;
            
            if(first!=second) {
                if(mp.find(second)!=mp.end())
                {
                    return {mp[first][0], mp[second][0]};
                }
            }
            else{
                if(mp[first].size()>1) return {mp[first][0],mp[first][1]};
            }
        }
        
        return {0,1};
    }
};