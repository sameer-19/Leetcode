class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        
        vector<int> t1(m*n),t2(m*n);
        
        int i,j,c=0;
        
        k=k%(m*n);
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                t1[c++]=(grid[i][j]);
            }
        }
        
        for(i=0;i<(m*n);i++)
        {
            t2[(i+k)%(m*n)]=t1[i];
        }
        
        c=0;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                grid[i][j]=t2[c++];
            }
        }
        
        return grid;
    }
};