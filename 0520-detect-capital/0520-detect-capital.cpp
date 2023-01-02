class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int cnt=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(word[i]>='A' and word[i]<='Z')
            {
                cnt++;
            }
        }
        
        if(cnt==n || cnt==0) 
        return true;
        
        cnt=0;
        
        for(int i=1;i<n;i++)
        {
            if(word[i]>='A' and word[i]<='Z') 
            {
                return false;
            }
        }
            
        return true;
    }
};