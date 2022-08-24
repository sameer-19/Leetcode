class Solution {
public:
    void solve(int idx,vector<int>& nums,vector<int> res,vector<vector<int>>& ans)
    {
        if(idx<0)
        {
            ans.push_back(res);
            return;
        }
        
        solve(idx-1,nums,res,ans);
        
        res.push_back(nums[idx]);
        solve(idx-1,nums,res,ans);
        
        // res.pop_back();
        
        
        return;
    }
        
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        vector<int> res;
        
        int i,j,n=nums.size();    
        
        solve(n-1,nums,res,ans);
        
        set<vector<int>> s;
        
        for(auto x: ans) s.insert(x);
        
        ans.clear();
        
        for(auto x: s) ans.push_back(x);
        
        return ans;
    }
};