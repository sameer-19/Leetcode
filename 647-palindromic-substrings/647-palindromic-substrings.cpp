class Solution {
public:
    int solve(int start,int end,string s,int n)
    {
        // length of the palindromic substring
        int cnt=0;
        
        while(start>=0 and end<n and s[start]==s[end]) start--,end++,cnt++;
        
        return cnt;
    }
    
    int countSubstrings(string s) {
        int n=s.length(),i,ans=0;
        
        for(i=0;i<n;i++)
        {
            ans+=solve(i,i,s,n);
            ans+=solve(i,i+1,s,n);
        }
        
        return ans;
    }
};