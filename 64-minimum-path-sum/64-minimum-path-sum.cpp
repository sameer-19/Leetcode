class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int i,j;
        
        vector<int> prev(n,0);
        vector<int> cur(n,0);
        
        prev[0]=grid[0][0];
        
        for(i=1;i<n;i++) prev[i]=prev[i-1]+grid[0][i];
        
        for(i=1;i<m;i++)
        {
            cur[0]=prev[0]+grid[i][0];
            
            for(j=1;j<n;j++) cur[j]=min(cur[j-1],prev[j])+grid[i][j];
            
            prev=cur;
        }
        
        return prev[n-1];
    }
};