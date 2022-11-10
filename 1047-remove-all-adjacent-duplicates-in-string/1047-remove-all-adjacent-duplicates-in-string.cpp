class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        
        int i,j,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(stk.empty()) stk.push(s[i]);
            else 
            {
                if(stk.top()==s[i]) stk.pop();
                else stk.push(s[i]);
            }
        }
        
        string ans;
        
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};