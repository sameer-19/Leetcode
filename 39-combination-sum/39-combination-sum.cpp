class Solution {
public:
void solve(int idx,int &target,int sum,vector<int>&nums,vector<int>&res,vector<vector<int>> &ans)
    {
        if(idx<0)
        {
            if(sum==target) ans.push_back(res);
            
            return;
        }
        
        solve(idx-1,target,sum,nums,res,ans);
        
        if(nums[idx]+sum<=target) 
        {
            sum+=nums[idx];    
            res.push_back(nums[idx]);
            solve(idx,target,sum,nums,res,ans);
            res.pop_back();
        }
    
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        vector<int> res;
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size(),sum=0;
        
        solve(n-1,target,sum,nums,res,ans);
        
        return ans;
    }
};