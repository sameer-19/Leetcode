class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length(),i,f=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else
            {
                if(st.empty()) { f=1;break;}
                if(s[i]==')' && st.top()=='(') st.pop();
                else if(s[i]=='}' && st.top()=='{') st.pop();
                else if(s[i]==']' && st.top()=='[') st.pop();
                else {f=1;break;}
            }
        }
        if(!st.empty() || f==1) return false;
        return true;
    }
};