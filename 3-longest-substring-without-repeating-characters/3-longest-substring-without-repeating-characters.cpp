class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0;
        int n=s.length();
        
        int ans=0;
        map<char,int> mp;
        
        while(right<n)
        {
            if(mp.find(s[right])!=mp.end())
            {
                left=max(left,mp[s[right]]+1);
            }
            mp[s[right]]=right;
            
            ans=max(ans,right-left+1);
            
            right++;
        }
        
        return ans;
    }
};