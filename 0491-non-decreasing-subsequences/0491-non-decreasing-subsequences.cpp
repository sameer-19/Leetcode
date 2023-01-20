class Solution {
public:
    void solve(int idx,int n,int prev,vector<int> &nums,vector<int> &res,set<vector<int>> &ans)
    {
        if(idx==n)
        {
            if(res.size()>1)
            ans.insert(res);
            return;
        }
        
        int oldPrev = prev;
        
        if(nums[idx]>=prev)
        {
            res.push_back(nums[idx]);
            solve(idx+1,n,nums[idx],nums,res,ans);
            res.pop_back();
        }
        
        solve(idx+1,n,prev,nums,res,ans);
        
        return;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        
        vector<vector<int>> finalAns;
        
        int n=nums.size();
        
        vector<int> res;
        
        solve(0,n,-200,nums,res,ans);
        
        for(auto x: ans) finalAns.push_back(x);
        
        return finalAns;
    }
};