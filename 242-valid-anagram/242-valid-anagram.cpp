class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        
        int a[26]={0},b[26]={0};
        
        int i,m=s.length(),n=t.length();
        
        for(i=0;i<m;i++)
        {
            a[s[i]-'a']++;
        }
        
        for(i=0;i<n;i++)
        {
            b[t[i]-'a']++;
        }
        
        for(i=0;i<26;i++)
        {
            if(a[i]!=b[i]) return false;
        }
        
        return true;
    }
};