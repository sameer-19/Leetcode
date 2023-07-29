class Solution {
public:
    
    bool solve(string s)
    {
        int left=0,right=s.length()-1;
        while(left<=right)
        {
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        
        return true;
    }
    
    bool check(char ch)
    {
        if(ch>='a' and ch<='z') return true;
        if(ch>='A' and ch<='Z') return true;
        if(ch>='0' and ch<='9') return true;
        
        return false;
    }
    
    bool isPalindrome(string str) {
        string s="";
        for(int i=0;i<str.length();i++)
        {
            bool res = check(str[i]);
            if(res and (str[i]>='A' and str[i]<='Z')) s+=tolower(str[i]);
            else if(res) s+=str[i];
        }
        
        return solve(s);
    }
};