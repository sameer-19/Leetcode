class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp)
    {
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up=0,left=0;
        up=solve(i-1,j,dp);
        left=solve(i,j-1,dp);
        
        return dp[i][j] = left + up;
    }
    
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        int i,j;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0 && j==0) dp[i][j]=1;
                else
                {
                    int left=0,up=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];

                    dp[i][j]=left+up;   
                }
            }
        }
        return dp[m-1][n-1];
    }
};