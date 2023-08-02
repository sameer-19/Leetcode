class Solution {
public:
    void solve(int n,int k,vector<int> &result,vector<vector<int>>&ans,vector<bool> &visited)
    {
        if(result.size()==k)
        {
            ans.push_back(result);
            return;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(result.size()>0)
            {
                if(result[result.size()-1]>=i) continue;
            }
            
            if(!visited[i])
            {
                visited[i]=true;
                result.push_back(i);
                solve(n,k,result,ans,visited);
                visited[i]=false;
                result.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        
        vector<int> result;
        vector<bool> visited(n+1,false);
        
        solve(n,k,result,ans,visited);
            
        return ans;
    }
};