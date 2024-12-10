class Solution {
public:
    int maximumLength(string s) {
        int ans = -1, n = s.length();
        
        map<string, int> mp;
        
        for(int i=0;i<n;i++)
        {
            string res = "";
            res+=s[i];
            mp[res]++;
            int j = i+1;
            while(j<n and s[j]==s[i])
            {
                res+=s[j];
                j++;
                mp[res]++;
            }
        }
        
        for(auto x: mp)
        {
            if(x.second>=3)
            {
                int strLength = x.first.length();
                ans = max(ans, strLength);
            }
        }
        
        return ans;
    }
};