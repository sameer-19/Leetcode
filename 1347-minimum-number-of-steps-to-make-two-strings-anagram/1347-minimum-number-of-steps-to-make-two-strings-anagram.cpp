class Solution {
public:
    int minSteps(string s, string t) {
        int a[26]={0},b[26]={0};
        
        int m=s.length(),n=t.length();
        
        int i,j;
        
        for(i=0;i<m;i++) a[s[i]-'a']++;
        for(i=0;i<n;i++) b[t[i]-'a']++;
        
        int ans=0;
        
        for(i=0;i<26;i++)
        {
            ans+=abs(a[i]-b[i]);
        }
        
        return ans/2;
    }
};