class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        
        int cnt=0,i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='L') cnt--;
            else cnt++;
            
            if(cnt==0) ans++;
        }
        
        
        return ans;
    }
};