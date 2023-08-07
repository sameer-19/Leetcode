class Solution {
public:
    int recursion(int i,int j,string &s1,string &s2)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(s1[i]==s2[j]) return 0 + recursion(i-1,j-1,s1,s2);
        
    return 1+ min({recursion(i,j-1,s1,s2),recursion(i-1,j,s1,s2),recursion(i-1,j-1,s1,s2)});
    }
    
    int memo(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(i==0) return j;
        if(j==0) return i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i-1]==s2[j-1]) return dp[i][j] = 0 + memo(i-1,j-1,s1,s2,dp);
        
        return dp[i][j] = 1+ min({memo(i,j-1,s1,s2,dp),
                       memo(i-1,j,s1,s2,dp),
                       memo(i-1,j-1,s1,s2,dp)});
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        
        // return recursion(n-1,m-1,word1,word2);
        
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        // Memoization
        return memo(n,m,word1,word2,dp);
        
    }
};