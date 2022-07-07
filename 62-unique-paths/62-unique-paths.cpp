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
        
        return solve(m-1,n-1,dp);
        
        // int a[105][105];
        // int i,j,ans=0;
        // for(i=0;i<m;i++)
        // {
        //     for(j=0;j<n;j++)
        //     {
        //         if(i==0 || j==0) a[i][j]=1;
        //     }
        // }
        // for(i=1;i<m;i++)
        // {
        //     for(j=1;j<n;j++)
        //     {
        //         a[i][j]=a[i-1][j]+a[i][j-1];
        //     }
        // }
        // ans=a[m-1][n-1];
        // return ans;
    }
};