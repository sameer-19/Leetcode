class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        
        if(n==0) return 0;
        int ans=1; // min. length = 1 (non-repeating character)
        
        unordered_map<char,int> mp;
        int left=0,right=0;
        
        while(right<n)
        {
            mp[s[right]]++;
            while(mp[s[right]]>1 and left<=right){
                mp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        
        return ans;
    }
};