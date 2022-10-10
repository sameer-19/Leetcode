class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.length();
        
        if(n==1) return "";
        
        vector<int> cnt(26,0);
        
        for(int i=0;i<(n/2);i++)
        {
            cnt[s[i]-'a']++;
        }
        
        if(cnt[0]==n/2)
        {
            s[n-1]='b';
        }
        else
        {
            for(int i=0;i<(n/2);i++)
            {
                if(s[i]!='a') 
                {
                    s[i]='a';
                    break;
                }
            }
        }
        
        return s;
    }
};