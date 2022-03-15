class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int i,j,n=s.length(),cnt=0;
        i=0;j=n-1;
        stack<int> st;
        vector<int> v;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.empty()) s[i]='#';
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty())
        {
            s[st.top()]='#';
            st.pop();
        }
        string res="";
        for(i=0;i<n;i++)
        {
            if(s[i]!='#') res+=s[i];
        }
        return res;
    }
};