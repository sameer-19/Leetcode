class Solution
{
    public:
        int lcs(int i, string a, int j, string b, vector<vector < int>> &dp)
        {
            if (i == 0 || j == 0) return 0;

            if (dp[i][j] != -1) return dp[i][j];

            if (a[i - 1] == b[j - 1]) return dp[i][j] = 1 + lcs(i - 1, a, j - 1, b,dp);

            return dp[i][j] = max(lcs(i, a, j - 1, b,dp), lcs(i - 1, a, j, b,dp));
        }

    int longestCommonSubsequence(string a, string b)
    {

        int m = a.length(), n = b.length(),i,j;

        vector<vector < int>> dp(m + 1, vector<int> (n + 1, 0));
        
        for(i=0;i<=n;i++) dp[0][i]=0;
        for(i=0;i<=m;i++) dp[i][0]=0;
    
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[m][n];
    }
};