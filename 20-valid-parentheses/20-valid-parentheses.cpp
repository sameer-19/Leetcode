class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        int n=s.length();
        
        int i,j;
        
        for(i=0;i<n;i++)
        {
            if((s[i]=='(') || (s[i]=='{') || (s[i]=='['))
            {
                stk.push(s[i]);   
            }
            else
            {
                if(stk.empty()) return false;
                
                if(stk.top()=='(')
                {
                    if(s[i]!=')') return false;
                    
                    stk.pop();
                }
                else if(stk.top()=='[')
                {
                    if(s[i]!=']') return false;
                    
                    stk.pop();
                }
                else
                {
                    if(s[i]!='}') return false;
                    
                    stk.pop();
                }
            }
        }
        
        if(!stk.empty()) return false;
        
        return true;
    }
};