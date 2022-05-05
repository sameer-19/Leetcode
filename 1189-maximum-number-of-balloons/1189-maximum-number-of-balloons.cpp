class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.length(),a[26]={0};
        
        int i,ans=INT_MAX;
        
        for(i=0;i<n;i++) a[text[i]-'a']++;
        
        ans=min(ans,a[1]);
        ans=min(ans,a[0]);
        ans=min(ans,a[11]/2);
        ans=min(ans,a[14]/2);
        ans=min(ans,a[13]);
        
        
        return ans;
    }
};