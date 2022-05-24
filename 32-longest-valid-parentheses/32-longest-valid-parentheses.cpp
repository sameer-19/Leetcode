class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        
        int i,j,ans=0;
        stack<int> st;
        st.push(-1);
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(') st.push(i);
            else
            {
                st.pop();
                if(st.empty()) st.push(i);
                else
                {
                    ans=max(ans,i-st.top());
                }
            }
        }
        
        return ans;
    }
};