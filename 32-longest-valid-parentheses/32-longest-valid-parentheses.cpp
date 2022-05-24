class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        
        int i,ans=0,open=0,close=0;
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(') open++;
            else close++;
            
            if(open==close) 
            {
                ans=max(ans,open+close);
            }
            else if(close>open)
            {
                open=close=0;
            }
        }
        
        open=close=0;
        
        for(i=n-1;i>=0;i--)
        {
            if(s[i]=='(') open++;
            else close++;
            
            if(open==close) ans=max(ans,open+close);
            else if(open>close){
                open=close=0;
            }
        }
        
        return ans;
    }
};