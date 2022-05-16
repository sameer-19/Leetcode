class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),i,j,k,l;
        int ans=0;
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        
        grid[0][0]=1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first,y=p.second;
            if(x==n-1 and y==n-1) return grid[n-1][n-1];
            
            for(auto d: dir)
            {
                int dx=x+d.first;
                int dy=y+d.second;
                
                if(dx>=0 and dx<n and dy>=0 and dy<n and grid[dx][dy]==0)
                {
                    q.push({dx,dy});
                    grid[dx][dy]=grid[x][y]+1;
                }
                
            }
            
        }
        
       
        return -1;
    }
};