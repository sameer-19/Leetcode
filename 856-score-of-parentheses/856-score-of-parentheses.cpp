class Solution {
public:
    int scoreOfParentheses(string s) {
        int i,ans=0,n=s.length();
        
        stack<int> st;
        st.push(-1);
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(-1);
            }
            else
            {
                int sum=0;
                while(!st.empty() and st.top()!=-1)
                {
                    sum+=st.top();
                    st.pop();
                }
                st.pop();
                st.push(max(2*sum,1));
            }
        }
        
        int sum=0;
        while(!st.empty() and st.top()!=-1)
        {
            sum+=st.top();
            st.pop();
        }
        st.pop();
        st.push(sum);
        ans=st.top();
        return ans;
    }
};