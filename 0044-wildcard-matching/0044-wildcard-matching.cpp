class Solution {
public:
    bool solve(int i,int j,string &p,string &s,vector<vector<int>> &dp)
    {
        if(i<0 and j<0) return true;
        if(i<0 and j>=0) return false;
        if(j<0)
        {
            for(int k=0;k<=i;k++)
            {
                if(p[k]!='*') return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(p[i]==s[j] || p[i]=='?') return dp[i][j]= solve(i-1,j-1,p,s,dp);
        
        if(p[i]=='*')
        {
            return dp[i][j]= (solve(i-1,j,p,s,dp)|solve(i,j-1,p,s,dp));
        }
        
        return dp[i][j]= false;
    }
    
    bool isMatch(string s, string p) {
        int m=p.size(),n = s.size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return solve(m-1,n-1,p,s,dp);
    }
};