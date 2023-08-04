class Solution {
public:
    bool solve(int idx,int n,string &s,bool &ans,unordered_map<string,bool> mp,
               vector<int> &dp)
    {
        if(idx==n)
        {
            return true;
        }
        
        if(dp[idx]!=-1) return dp[idx];
        
        string res="";
        
        for(int i=idx;i<n;i++)
        {
            res+=s[i];
            if(mp[res])
            {
                if(solve(i+1,n,s,ans,mp,dp)) return dp[idx]= true;
            }
        }
        
        return dp[idx]= false;
    }
        
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> mp;
        int n=s.length();
        
        for(auto x: wordDict) mp[x]=1;
        
        bool ans=false;
        
        vector<int> dp(n+1,-1);
        
        return solve(0,n,s,ans,mp,dp);
        
        // return ans;
    }
};