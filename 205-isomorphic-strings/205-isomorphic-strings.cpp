class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int c1[10005];
        int c2[10005];
        
        memset(c1,-1,sizeof(c1));
        memset(c2,-1,sizeof(c2));
        
        for(int i=0;i<s.length();i++)
        {
            if(c1[s[i]]==-1 and c2[t[i]]==-1)
            {
                c1[s[i]]=t[i];
                c2[t[i]]=s[i];
            }
            else if(!(c1[s[i]]==t[i] and c2[t[i]]==s[i]))
            {
                return false;
            }
        }
        return true;
    }
};