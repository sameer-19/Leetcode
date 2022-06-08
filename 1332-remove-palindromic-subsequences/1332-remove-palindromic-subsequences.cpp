class Solution {
public:
    int removePalindromeSub(string s) {
        bool f=false;
        
        int i=0,j=s.length()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                f=true;
                break;
            }
            i++;j--;
        }
        
        if(f) return 2;
        return 1;
    }
};