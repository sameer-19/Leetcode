class Solution {
public:
    string longestPalindrome(string s) {

        int n=s.length();
        int i,j,ans=0,id1=0,id2=0,left,right;
        string result="";
        
        
        // for considering the odd length strings
        for(i=0;i<n;i++)
        {
            left=right=i;
            while(left>=0 and right<n and s[left]==s[right]) left--,right++;
            if(ans<right-left-1)
            {
                ans=right-left-1;
                id1=left+1;
                id2=right-1;
            }
        }
        // for considering the even length strings
        for(i=0;i<n-1;i++)
        {
            left=right=i;
            ++right;
            while(left>=0 and right<n and s[left]==s[right]) left--,right++;
            if(ans<right-left)
            {
                ans=right-left;
                id1=left+1;
                id2=right-1;
            }
        }
        
        for(i=id1;i<=id2;i++) result+=s[i];
        
        return result;
    }
};