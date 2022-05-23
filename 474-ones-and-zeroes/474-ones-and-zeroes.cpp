class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        int i,j;
        
        for(i=0;i<=m;i++) 
        {
            for(j=0;j<=n;j++) dp[i][j]=0;
        }
        
        for(auto x: strs)
        {
            int c0=0,c1=0;
            for(auto y: x) 
            {
                if(y=='0') c0++;
                else c1++;
            }
            
            for(int zero=m;zero>=c0;zero--)
            {
                for(int one=n;one>=c1;one--)
                {
                    dp[zero][one]=max(dp[zero-c0][one-c1]+1,dp[zero][one]);
                }
            }   
        }
        
        return dp[m][n];
    }
};