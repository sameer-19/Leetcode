class Solution {
public:
    
    void dfs(int node,vector<vector<int>>& graph,vector<int>&result,int target,vector<vector<int>> &ans)
    {
        if(node==target)
        {
            ans.push_back(result);
            return;
        }
        
        for(auto neighbor: graph[node])
        {
            result.push_back(neighbor);
            
            dfs(neighbor,graph,result,target,ans);
                
            result.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        
        int n=graph.size();
        
        vector<int> result;
        result.push_back(0);
        
        dfs(0,graph,result,n-1,ans);
        
        return ans;
    }
};