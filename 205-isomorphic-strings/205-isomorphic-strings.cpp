class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int i,a[256],b[256],n=s.length();
        
        for(i=0;i<256;i++)
        {
            a[i]=-1;
            b[i]=-1;
        }
        
        for(i=0;i<n;i++)
        {
            if(a[s[i]]==-1 and b[t[i]]==-1)
            {
                a[s[i]]=t[i];
                b[t[i]]=s[i];
            }
            else if(a[s[i]]==-1 || b[t[i]]==-1) return false;
            else if(!(a[s[i]]==t[i] and b[t[i]]==s[i]))
            {
                return false;
            }
        }
        
        
        return true;
    }
};