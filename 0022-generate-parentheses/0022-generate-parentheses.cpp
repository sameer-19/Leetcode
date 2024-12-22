class Solution {
public:
    void solve(int &open, int &close, string &s, vector<string> &ans)
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
            solve(open, close, s, ans);
            open++;
            s.pop_back();
        }
        
        if(close>open){
            s+=')';
            close--;
            solve(open, close, s, ans);
            close++;
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string res = "";
        int open = n, close = n;
        vector<string> ans;
        
        solve(open, close, res, ans);
        
        return ans;
    }
};