class Solution {
public:
    // Memoization
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
    
    bool solve2(int i,int j,string &p,string &s,vector<vector<int>> &dp)
    {
        if(i==0 and j==0) return true;
        if(i==0 and j>0) return false;
        if(j==0)
        {
            for(int k=1;k<=i;k++)
            {
                if(p[k-1]!='*') return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(p[i-1]==s[j-1] || p[i-1]=='?') return dp[i][j]= solve2(i-1,j-1,p,s,dp);
        
        if(p[i-1]=='*')
        {
            return dp[i][j]= (solve2(i-1,j,p,s,dp)|solve2(i,j-1,p,s,dp));
        }
        
        return dp[i][j]= false;
    }
    
    bool tabulation(int m,int n,string &p,string &s,vector<vector<bool>> &dp)
    {
        dp[0][0]=true;
        
        for(int j=1;j<=n;j++)
        {
            dp[0][j]=false;
        }
        
        for(int i=1;i<=m;i++)
        {
            bool flag=true;
            for(int k=1;k<=i;k++)
            {
                if(p[k-1]!='*') 
                {
                    flag=false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[i-1]==s[j-1] || p[i-1]=='?') dp[i][j]= dp[i-1][j-1];
                else if(p[i-1]=='*')
                {
                     dp[i][j]= (dp[i-1][j]|dp[i][j-1]);
                }
                else dp[i][j]=false;
            }
        }
        
        return dp[m][n];
    }
    
    bool spaceOptimization(int m,int n,string &p,string &s)
    {
        vector<bool> prev(n+1,false),cur(n+1,false);
        prev[0]=true;
        
        for(int j=1;j<=n;j++)
        {
            prev[j]=false;
        }
        
        for(int i=1;i<=m;i++)
        {
            bool flag=true;
            for(int k=1;k<=i;k++)
            {
                if(p[k-1]!='*') 
                {
                    flag=false;
                    break;
                }
            }
            cur[0] = flag;
            
            for(int j=1;j<=n;j++)
            {
                if(p[i-1]==s[j-1] || p[i-1]=='?') cur[j]= prev[j-1];
                else if(p[i-1]=='*')
                {
                     cur[j]= prev[j]|cur[j-1];
                }
                else cur[j]=false;
            }
            prev = cur;
        }
        
        return prev[n];
    }
    
    bool isMatch(string s, string p) {
        int m=p.size(),n = s.size();
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
        
        // Tabulation
        // return tabulation(m,n,p,s,dp);
        
        // Space Optimization
        return spaceOptimization(m,n,p,s);
    }
};