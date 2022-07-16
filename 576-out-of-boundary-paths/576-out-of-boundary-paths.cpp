class Solution {
public:
    int MOD = (int)1e9+7;
    
    int solve(int i,int j,int m,int n,int mxMove,
              vector<vector<vector<int>>> &dp)
    {
        if(i<0 || i>=m || j<0 || j>=n) 
        {
            return 1;
        }
        
        if(mxMove==0) return 0;
        
        if(dp[i][j][mxMove]!=-1) return dp[i][j][mxMove];
        
        dp[i][j][mxMove] = solve(i,j+1,m,n,mxMove-1,dp)%MOD ;
        dp[i][j][mxMove] += solve(i,j-1,m,n,mxMove-1,dp)%MOD;
        dp[i][j][mxMove]%=MOD;
        dp[i][j][mxMove] += solve(i+1,j,m,n,mxMove-1,dp)%MOD;
        dp[i][j][mxMove]%=MOD;
        dp[i][j][mxMove] += solve(i-1,j,m,n,mxMove-1,dp)%MOD;
        
        return dp[i][j][mxMove]%MOD;
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove==0) return 0;
        
        int ans=0;
vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (n+1,vector<int> (maxMove+1,-1)));
        
        return solve(startRow,startColumn,m,n,maxMove,dp);
        
    }
};