class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        unordered_map<int,int> mp;
        
        // Time complexity- O(N)
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        // Space Complexity- O(N)
        vector<vector<int>> res(nums.size()+1);
        
        for(auto x: mp)
        {
            res[x.second].push_back(x.first);
        }
        
        // Time complexity- O(N)
        for(int i=nums.size();i>=1;i--)
        {
            int j=0;
            while(k>0 and j<res[i].size())
            {
                ans.push_back(res[i][j]);
                j++;
                k--;
            }
            if(k==0) break;
        }
        
        return ans;
    }
};