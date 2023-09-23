class Solution {
public:
    static bool cmp(string &a,string &b)
    {
        if(a.length()<b.length()) return true;
        else if(a.length()==b.length()) return a<b;
        
        return false;
    }
    
    bool compare(string &prev,string &cur)
    {
        int m=prev.length(), n = cur.length();
        
        if(n-m!=1) return false;
        
        int i = 0, j = 0;
        
        while(j<n)
        {
            if(prev[i]==cur[j]) {i++; j++;}
            else
            {
                j++;
            }
        }
        
        if(i==m and j==n) return true;
        return false;
    }
    
    
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        
        int n = words.size(), ans = 1;
        
        vector<int> dp(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int prev_idx = 0;prev_idx<i;prev_idx++)
            {
                if(compare(words[prev_idx],words[i]))
                {
                    dp[i] = max(dp[i],1+dp[prev_idx]);
                    ans = max(ans,dp[i]);
                }
            }
        }
        
        return ans;
    }
};