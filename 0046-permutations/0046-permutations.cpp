class Solution {
public:
    void solve(vector<int> &nums,vector<int> &result,vector<vector<int>> &ans,vector<bool> &visited)
    {
        if(result.size()==nums.size()) 
        {
            ans.push_back(result);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(!visited[i])
            {
                result.push_back(nums[i]);
                visited[i]=true;
                solve(nums,result,ans,visited);
                result.pop_back();
                visited[i]=false;
            }
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        vector<int> result;
        
        vector<bool> visited(nums.size(),false);
        
        solve(nums,result,ans,visited);
        
        return ans;
    }
};