class Solution {
public:
    void solve(int n,vector<int> &nums,vector<int> &result,
               vector<vector<int>> &ans,vector<bool>&visited)
    {
        if(result.size()==n)
        {
            ans.push_back(result);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i])
            {
                visited[i]=true;
                result.push_back(nums[i]);
                solve(n,nums,result,ans,visited);
                result.pop_back();
                visited[i]=false;
            }
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        vector<int> result;
        
        int n=nums.size();
        vector<bool> visited(n,false);
        
        solve(n,nums,result,ans,visited);
        
        return ans;
    }
};