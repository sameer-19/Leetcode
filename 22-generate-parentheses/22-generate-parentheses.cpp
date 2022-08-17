class Solution {
public:
    void solve(string &s,int &open,int &close,vector<string> &ans)
    {
        if(open==close and open==0)
        {
            ans.push_back(s);
            return;
        }
        
        if(open>0)
        {
            s+='(';
            open--;
            solve(s,open,close,ans);
            open++;
            s.pop_back();
        }
        
        if(close>open)
        {
            s+=')';
            close--;
            solve(s,open,close,ans);
            close++;
            s.pop_back();
        }
        
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";    
        int open=n,close=n;
        
        solve(s,open,close,ans);
        
        return ans;
    }
};