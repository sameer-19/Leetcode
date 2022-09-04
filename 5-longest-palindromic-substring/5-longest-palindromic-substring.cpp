class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        
        int n=s.length(),i,j,res=0;
        
        int left,right;
        int leftIdx=-1,rightIdx=1;
        
        for(i=0;i<n;i++)
        {
            // even length
            left=i; right=i+1;
            while(left>=0 and right<n and s[left]==s[right])
            {
                left--;
                right++;
            }
            
            if(res<right-left-1)
            {
                leftIdx=left;
                rightIdx=right;
                res=right-left-1;
            }
            
            // odd length
            left=i-1;right=i+1;
            while(left>=0 and right<n and s[left]==s[right])
            {
                left--;
                right++;
            }
            
            if(res<right-left-1)
            {
                leftIdx=left;
                rightIdx=right;
                res=right-left-1;
            }
        }
        
        // cout<<leftIdx<<" "<<
            
        for(i=leftIdx+1;i<rightIdx;i++) ans+=s[i];
        
        return ans;
    }
};