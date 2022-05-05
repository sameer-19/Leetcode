class Solution {
public:
    bool alphabet(char ch)
    {
        if(ch>='a' and ch<='z') return true;
        if(ch>='A' and ch<='Z') return true;
        
        return false;
    }
    
    string reverseOnlyLetters(string s) {
        int n=s.length();
        
        int i=0,j=n-1;
        while(i<j)
        {
            if(alphabet(s[i]) and alphabet(s[j]))
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(alphabet(s[i])) j--;
            else if(alphabet(s[j])) i++;
            else i++,j--;
        }
        return s;
    }
};