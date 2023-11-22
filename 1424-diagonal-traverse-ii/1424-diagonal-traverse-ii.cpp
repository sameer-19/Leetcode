class Solution {
public:
    vector<int> solve(vector<vector<int>>& nums)
    {
        vector<int> ans;
        queue<pair<int, int>> queue;
        
        queue.push({0, 0});
        
        while (!queue.empty()) 
        {
            auto [row, col] = queue.front();
            queue.pop();
            
            ans.push_back(nums[row][col]);
            
            if (col == 0 && row + 1 < nums.size()) 
            {
                queue.push({row + 1, col});
            }
            
            if (col + 1 < nums[row].size()) 
            {
                queue.push({row, col + 1});
            }
        }
        
        return ans;
    }
    
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        return solve(nums);
        
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