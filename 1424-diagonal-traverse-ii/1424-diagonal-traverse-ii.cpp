class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        map<int,vector<int>> mp;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            int sz = nums[i].size();
            for(int j=0;j<sz;j++)
            {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        
        for(auto x: mp)
        {
            for(auto y: x.second) ans.push_back(y);    
        }
        
        return ans;
    }
};