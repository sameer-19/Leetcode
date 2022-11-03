class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        
        int ans=0,n=words.size(),f=0;
        
        for(int i=0;i<n;i++)
        {
            mp[words[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(words[i])!=mp.end())
            {
                string s=words[i];
                reverse(s.begin(),s.end());
                
                if(mp.find(s)!=mp.end())
                {
                    if(s==words[i] and mp[s]==1) 
                    {
                        f=1;
                        mp[s]--;
                        if(mp[s]==0) mp.erase(s);
                    }
                    else 
                    {
                        ans+=2;
                        mp[s]--;
                        mp[words[i]]--;
                        if(mp[s]==0) mp.erase(s);
                        if(mp[words[i]]==0) mp.erase(words[i]);
                    }
                }                
            }
        }
        
        return (ans+f)*2;
    }
};