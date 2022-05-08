class Solution {
public:
    string out(string a)
    {
        string s="";
        for(int i=1;i<a.length()-1;i++) s+=a[i];
        return s;
    }
    
    string removeOuterParentheses(string s) {
        string ans="";
        
        stack<char> st;
        
        int i,n=s.length();
        string tmp="";
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(') st.push(s[i]),tmp+=s[i];
            else
            {
                tmp+=s[i];
                st.pop();
                if(st.empty()) 
                {
                    ans+=out(tmp);
                    tmp="";
                }
            }
        }
        
        
        return ans;
    }
};