class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.length(),m=t.length();
        
        int i;
        
        string s1="",t1="";
        
        for(i=0;i<n;i++)
        {
            if(s[i]!='#') s1+=s[i];
            else 
            {
                if(s1.length()>0)
                {
                    s1.pop_back();
                }
            }
        }
        
        for(i=0;i<m;i++)
        {
            if(t[i]!='#') t1+=t[i];
            else 
            {
                if(t1.length()>0)
                {
                    t1.pop_back();
                }
            }
        } 
        
        return (s1==t1);
    }
};