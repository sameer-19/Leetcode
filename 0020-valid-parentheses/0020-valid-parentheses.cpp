class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int i=0;
        
        while(i<s.length())
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') stk.push(s[i]);
            else
            {
                if(stk.empty()) return false;
                else if(s[i]==')')
                {
                    if(stk.top()=='(') stk.pop();
                    else return false;
                }
                else if(s[i]=='}')
                {
                    if(stk.top()=='{') stk.pop();
                    else return false;
                }
                else 
                {
                    if(stk.top()=='[') stk.pop();
                    else return false;
                }
            }
            i++;
        }
        
        return stk.empty();
    }
};