class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<char>> &grid,
                                                        vector<vector<bool>> &visited)
    {
        if(i<0 || i>=m || j<0 || j>=n) return;
        if(grid[i][j]=='0') return;
        if(visited[i][j]) return;
        
        visited[i][j]=true;
        
        int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
        
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k],y=j+dy[k];
            
            dfs(x,y,m,n,grid,visited);
        }
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans=0,i,j;
        
        int m=grid.size(),n=grid[0].size();
        
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    if(!visited[i][j])
                    {
                        ans++;
                        dfs(i,j,m,n,grid,visited);
                    }
                }
            }
        }
        
        return ans;
    }
};
