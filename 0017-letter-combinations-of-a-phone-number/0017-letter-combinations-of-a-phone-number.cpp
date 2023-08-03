class Solution {
public:
    void solve(int idx,string &result,vector<string> &str,int &n,vector<string> &ans)
    {
        if(idx==n)
        {
            ans.push_back(result);
            return;
        }
        
        for(int i=0;i<str[idx].size();i++)
        {
            result+=str[idx][i];
            solve(idx+1,result,str,n,ans);
            result.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        int len= digits.length();
        
        if(len==0) return ans;
        
        string result="";
        
        vector<string> str;
        map<char,string> mp;
        mp['2']="abc";mp['3']="def";mp['4']="ghi";mp['5']="jkl";
        mp['6']="mno";mp['7']="pqrs";mp['8']="tuv";mp['9']="wxyz";
        
        for(int i=0;i<len;i++)
        {
            str.push_back(mp[digits[i]]);
        }
        
        solve(0,result,str,len,ans);
        
        return ans;
    }
};