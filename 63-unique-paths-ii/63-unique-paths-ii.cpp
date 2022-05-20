class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        
        int i,j;
        
        if(grid[0][0]==1 || grid[row-1][col-1]==1) return 0;
        
        vector<vector<int>> dp(row,vector<int> (col,0));
        
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(grid[i][j]==1) dp[i][j]=-1;
            }
        }
        
        dp[0][0]=1;
        
        for(i=1;i<col;i++)
        {
            if(grid[0][i]==0 and dp[0][i-1]>0) dp[0][i]=dp[0][i-1];
            else dp[0][i]=-1;
        }
        
        for(i=1;i<row;i++)
        {
            if(grid[i][0]==0 and dp[i-1][0]>0) dp[i][0]=dp[i-1][0];
            else dp[i][0]=-1;
        }
        
        for(i=1;i<row;i++)
        {
            for(j=1;j<col;j++)
            {
                if(grid[i][j]==0)
                {
                    dp[i][j] += (dp[i-1][j]>0) ? dp[i-1][j] : 0;
                    dp[i][j] += (dp[i][j-1]>0) ? dp[i][j-1] : 0;
                }
            }
        }
        
        return dp[row-1][col-1];
        
    }
};