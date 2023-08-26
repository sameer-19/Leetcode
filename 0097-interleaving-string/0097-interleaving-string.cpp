class Solution {
public:
    bool recursion(int i,int j,int k,string &s1,string &s2,string &s3)
    {
        if(k<0) return true;
        
        if(i>=0 and j>=0 and s1[i]==s3[k] and s2[j]==s3[k])
        {
            return recursion(i-1,j,k-1,s1,s2,s3)|recursion(i,j-1,k-1,s1,s2,s3);
        }
        if(i>=0 and s1[i]==s3[k]) return recursion(i-1,j,k-1,s1,s2,s3);
        if(j>=0 and s2[j]==s3[k]) return recursion(i,j-1,k-1,s1,s2,s3);
        
        return false;
    }
    
    bool memo(int i,int j,int k,string &s1,string &s2,string &s3,
              vector<vector<vector<int>>> &dp)
    {
        if(k==0) return true;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        if(i>=1 and j>=1 and s1[i-1]==s3[k-1] and s2[j-1]==s3[k-1])
        {
            return dp[i][j][k] = memo(i-1,j,k-1,s1,s2,s3,dp)|memo(i,j-1,k-1,s1,s2,s3,dp);
        }
        if(i>=1 and s1[i-1]==s3[k-1]) return dp[i][j][k] = memo(i-1,j,k-1,s1,s2,s3,dp);
        if(j>=1 and s2[j-1]==s3[k-1]) return dp[i][j][k] = memo(i,j-1,k-1,s1,s2,s3,dp);
        
        return dp[i][j][k] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),m=s2.length(),k = s3.length();
        if((m+n)!=k) return false;
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (m+1,vector<int> (k+1,-1)));
        
        return memo(n,m,k,s1,s2,s3,dp);
        // return recursion(n-1,m-1,k-1,s1,s2,s3);
        
    }
};