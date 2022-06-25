class Solution {
public:
    string removeDuplicateLetters(string s) {
        int lastIndex[26];
        
        bool visited[26]={false};
        
        stack<char> st;
        
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            lastIndex[s[i]-'a']=i;
        }
        
        for(i=0;i<n;i++)
        {
            char ch = s[i]-'a';
            
            if(visited[ch]) continue;
            else
            {
                while(!st.empty() and st.top()>s[i] and i<lastIndex[st.top()-'a'])
                    visited[st.top()-'a']=false , st.pop();
                
                st.push(s[i]);
                visited[ch]=true;
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