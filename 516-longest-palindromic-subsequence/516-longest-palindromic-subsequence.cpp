class Solution {
public:
    int solve(int start,int end,string &s,int& n,vector<vector<int>>& v)
    {
        if(start>end) return 0;
        if(start==end) return 1;
        if(v[start][end]) return v[start][end];
        return v[start][end] = s[start]==s[end] ? 2+solve(start+1,end-1,s,n,v) : max(solve(start+1,end,s,n,v),solve(start,end-1,s,n,v));
    }
    
    int longestPalindromeSubseq(string s) {
        int n=s.length(),i,ans=0;
        vector<vector<int>> v(n,vector<int> (n,0));
        
        ans=solve(0,n-1,s,n,v);
        
        return ans;
    }
};