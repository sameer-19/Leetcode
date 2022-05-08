class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        
        int cnt=0,ans=0;
        
        for(auto x: s)
        {
            if(x=='(') 
            {
                cnt++;
                ans=max(ans,cnt);
                st.push(x);
            }
            else if(x!=')') st.push(x);
            else
            {
                cnt--; 
                ans=max(ans,cnt);
                while(!st.empty() and st.top()!='(') st.pop();
                st.pop();
            }
        }
        return ans;
    }
};