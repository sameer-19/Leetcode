class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0,right=0,ans=0;
        
        map<char,int> mp;
        
        int n=s.length();
        
        while(right<n)
        {
            mp[s[right]]++;
            
            while(mp['a'] and mp['b'] and mp['c'])
            {
                ans+=n-right;
                mp[s[left]]--;
                left++;
            }
            
            right++;
        }
                
        return ans;
    }
};