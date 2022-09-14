class Solution {
public:
    int solve(int idx,string &s,unordered_map<string,int> mp,vector<int> &dp)
    {
        if(idx==s.length()) return true;
        
        
        if(dp[idx]!=-1) return dp[idx]; 
        
        string res="";
        for(int i=idx;i<s.length();i++)
        {
            res+=s[i];
            if(mp[res]>0)
            {
                // cout<<res<<" ";
                if(solve(i+1,s,mp,dp)) return dp[idx] = true;
            }
        }
        
        return dp[idx] = false;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        
        unordered_map<string,int> mp;
        vector<int> dp(n,-1);
        
        for(auto x: wordDict) mp[x]++;
        
        return solve(0,s,mp,dp);
    }
};