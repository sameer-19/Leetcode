class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(st.empty() || st.top().first!=s[i]) st.push({s[i],1});
            else
            {
                pair<char,int> prev=st.top();
                st.pop();
                st.push({s[i],prev.second+1});
            }
            
            if(st.top().second==k) st.pop();
        }
        
        string ans="";
        while(!st.empty())
        {
            pair<char,int> p=st.top();
            st.pop();
            while(p.second--) ans+=p.first;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};