class Solution {
public:
    int solve(int left,int right,string s)
    {
        int n=s.length();
        int ans = 0;
        
        while(left>=0 and right<n and s[left]==s[right])
        {
            left--;
            right++;
            ans++;
        }
        
        return ans;
    }
    
    int countSubstrings(string s) {
        int n=s.length();
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            ans+=solve(i,i,s);
            ans+=solve(i,i+1,s);
        }
        
        return ans;
    }
};