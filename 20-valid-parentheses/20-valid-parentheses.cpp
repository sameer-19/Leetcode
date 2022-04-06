class Solution {
public:
    bool isValid(string s) {
        int n=s.length(),i;
        if(n==1) return false;
        
        stack<char> st;
        if(s[0]==')' || s[0]==']' || s[0]=='}') return false;
        
        st.push(s[0]);
        for(i=1;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            else
            {
                if(st.empty()) return false;
                if(s[i]==')') { if(st.top()=='(') st.pop(); else return false; }
                else if(s[i]==']') { if(st.top()=='[') st.pop(); else return false; }
                else{ if(st.top()=='{') st.pop(); else return false; }
            }
        }
        return st.empty();
    }
};