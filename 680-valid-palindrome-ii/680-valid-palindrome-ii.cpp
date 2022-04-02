class Solution {
public:
    bool check(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
        
    
    bool validPalindrome(string s) {
        int i,j,n=s.length(),cnt=0,id1=0,id2=0;
        i=0;j=n-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return (check(s,i,j-1) || check(s,i+1,j));
            }
            i++;j--;
        }
        return true;
    }
};