class Solution {
public:
    bool check(char ch)
    {
        if(ch>='a' and ch<='z') return true;
        if(ch>='A' and ch<='Z') return true;
        if(ch>='0' and ch<='9') return true;
        return false;
    }
    
    bool isPalindrome(string s) {
        int n=s.length();
        
        int left=0,right=n-1;
        while(left<right)
        {
            if(check(s[left]) and check(s[right]))
            {
                if(s[left]>='A' and s[left]<='Z')
                s[left]=tolower(s[left]);
                if(s[right]>='A' and s[right]<='Z')
                s[right]=tolower(s[right]);
                if(s[left]!=s[right]) return false;
                left++;
                right--;
            }
            else if(check(s[left]))
            {
                right--;
            }
            else if(check(s[right]))
            {
                left++;
            }
            else
            {
                left++;
                right--;
            }
        }
        
        return true;
    }
};