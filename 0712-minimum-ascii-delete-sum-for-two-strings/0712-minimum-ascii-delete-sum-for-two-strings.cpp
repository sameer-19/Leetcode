class Solution {
public:
    int lcs(string s1,string s2)
    {
        int m=s1.length(),n=s2.length();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        
        for(int i=1;i<=n;i++) dp[0][i]= dp[0][i-1] +(int)s2[i-1];
        for(int i=1;i<=m;i++) dp[i][0]= dp[i-1][0] +(int)s1[i-1];
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else
                {
                    int top = dp[i-1][j]+(int)s1[i-1];
                    int left = dp[i][j-1]+(int)s2[j-1];
                    dp[i][j]=min(top,left);
                }
            }
        }
        
        // for(int i=0;i<=m;i++)
        // {
        //     for(int j=0;j<=n;j++) cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        
        return dp[m][n];
    }
    
    
    int minimumDeleteSum(string s1, string s2) {
        return lcs(s1,s2);
    }
};