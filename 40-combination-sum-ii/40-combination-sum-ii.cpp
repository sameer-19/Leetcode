class Solution {
public:
    void solve(int idx,int &target,
               vector<int> &nums,vector<int> &res,vector<vector<int>> &ans)
    {
        if(target==0)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx and nums[i]==nums[i-1]) continue;
        
            if(target-nums[i]<0) break;
            
            target-=nums[i];
            res.push_back(nums[i]);
            solve(i+1,target,nums,res,ans);
            target+=nums[i];
            res.pop_back();
        }
        
        
        return;
    }
        
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        // reverse(nums.begin(),nums.end());
        
        vector<int> result;
        
        int n=nums.size();
        
        solve(0,target,nums,result,ans);
        
        set<vector<int>> s;
        
        for(auto x: ans) s.insert(x);
        ans.clear();
        for(auto x: s) ans.push_back(x);
        
        return ans;
    }
};