class Solution {
public:
    bool check(char a,char b)
    {
        if((a-'a')==(b-'A')) return true;
        if((a-'A')==(b-'a')) return true;
        
        return false;
    }
    
    string makeGood(string s) {
        stack<char> st;
        
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(st.empty()) st.push(s[i]);
            else
            {
                if(check(st.top(),s[i]))
                {
                    st.pop();
                }
                else st.push(s[i]);
            }
        }
        
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};