class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        
        int ans=0,f=0;
        
        for(auto x: mp)
        {
            if(x.second%2!=0) 
            {
                ans+=(x.second-1);
                f=1;
            }
            else
            {
                ans+=x.second;
            }
        }
        
        if(f) ans++;
        
        return ans;
    }
};