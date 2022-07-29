class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        
        int i=0,m=s.length(),n=t.length();
        
        while(i<m)
        {
            if(s[i]!='#')
            {
                s1.push(s[i]);
            }
            else
            {
                if(s1.size()>0)
                s1.pop();
            }
            i++;
        }
        
        i=0;
        while(i<n)
        {
            if(t[i]!='#')
            {
                s2.push(t[i]);
            }
            else
            {
                if(s2.size()>0)
                s2.pop();
            }
            i++;
        }
        
        if(s1.size()!=s2.size()) return false;
        
        while(!s1.empty())
        {
            if(s1.top()!=s2.top()) return false;
            s1.pop();
            s2.pop();
        }
        
        return true;
    }
};