class Solution {
public:
    void solve(vector<int> &res,vector<int> &nums,int n,vector<vector<int>> &ans,bool visited[])
    {
        if(res.size()==n)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                res.push_back(nums[i]);
                visited[i]=true;
                solve(res,nums,n,ans,visited);
                visited[i]=false;
                res.pop_back();
            }
        }
        return;
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        int len=nums.size();
        bool visited[100]={false};
        solve(res,nums,len,ans,visited);
        set<vector<int>> st;
        for(auto x: ans) st.insert(x);
        ans.clear();
        for(auto x: st) ans.push_back(x);
        return ans;
    }
};