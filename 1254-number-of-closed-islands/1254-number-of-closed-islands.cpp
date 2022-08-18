class Solution {
public:
    
    bool dfs(int i,int j,int &m,int &n,vector<vector<int>>& grid,vector<vector<bool>>& visited)
    {
        if(i==0 || i==m-1 || j==0 || j==n-1)
        {
            return grid[i][j]==1;
        }
        if(grid[i][j]==1) return true;
        
        if(visited[i][j]) return true;
        
        visited[i][j]=true;
        
        int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
        
        int flag=0;
        
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k],y=j+dy[k];
            if(!visited[x][y])
            {
                if(dfs(x,y,m,n,grid,visited)==false) flag=1;
            }
        }
        
        return flag==0;
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        
        int i,j;
        int m=grid.size(),n=grid[0].size();
        
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        
        for(i=1;i<m-1;i++)
        {
            for(j=1;j<n-1;j++)
            {
                if(grid[i][j]==0)
                {
                    if(!visited[i][j])
                    {
                        if(dfs(i,j,m,n,grid,visited)) ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};