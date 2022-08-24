class Solution {
public:
    bool isPalindrome(string s,int left,int right)
    {
        while(left<=right)
        {
            if(s[left++]!=s[right--]) return false;
        }
        return true;
    }
    
    void solve(int idx,string s,vector<string> &path,vector<vector<string>> &ans)
    {
        if(idx==s.length())
        {
            ans.push_back(path);
            return;
        }
        
        for(int i=idx;i<s.length();i++)
        {
            if(isPalindrome(s,idx,i))
            {
                path.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,path,ans);
                path.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        
        solve(0,s,path,ans);
        
        return ans;
    }
};