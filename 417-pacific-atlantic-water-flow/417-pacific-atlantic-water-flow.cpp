class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<bool>> atlantic,pacific;
    
    
    void dfs(int i,int j,int m,int n,vector<vector<bool>> &visited,vector<vector<int>>& heights)
    {
        if(i<0 || i>=m || j<0 || j>=n) return;
        if(visited[i][j]) return;
        visited[i][j]=true;
        
        if(atlantic[i][j] and pacific[i][j]) ans.push_back({i,j});
        
        if(i+1<m and heights[i+1][j]>=heights[i][j]) dfs(i+1,j,m,n,visited,heights);
        if(i-1>=0 and heights[i-1][j]>=heights[i][j]) dfs(i-1,j,m,n,visited,heights);
        if(j+1<n and heights[i][j+1]>=heights[i][j]) dfs(i,j+1,m,n,visited,heights);
        if(j-1>=0 and heights[i][j-1]>=heights[i][j]) dfs(i,j-1,m,n,visited,heights);
    
        return;
    }   
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int i,j,m=heights.size(),n=heights[0].size();
        
        atlantic = pacific = vector<vector<bool>> (m,vector<bool> (n,false));
        
        for(i=0;i<m;i++) dfs(i,0,m,n,atlantic,heights),dfs(i,n-1,m,n,pacific,heights);
        
        for(i=0;i<n;i++) dfs(0,i,m,n,atlantic,heights),dfs(m-1,i,m,n,pacific,heights);
        
        return ans;
    }
};