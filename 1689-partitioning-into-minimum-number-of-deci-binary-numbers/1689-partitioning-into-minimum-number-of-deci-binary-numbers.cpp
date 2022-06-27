class Solution {
public:
    int minPartitions(string s) {
        int ans=0;
        
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            ans=max(ans,s[i]-'0');
        }
        
        return ans;
    }
};