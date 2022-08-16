class Solution {
public:
    int firstUniqChar(string s) {
        int a[26]={0};
        
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            a[s[i]-'a']++;
        }
        
        for(i=0;i<n;i++)
        {
            if(a[s[i]-'a']==1) return i;
        }
        
        return -1;
    }
};