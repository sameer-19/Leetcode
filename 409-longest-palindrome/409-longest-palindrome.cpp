class Solution {
public:
    int longestPalindrome(string s) {
        int a[26]={0},b[26]={0};
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(s[i]-'a'>=0 and s[i]-'a'<=25)
            a[s[i]-'a']++;
            else b[s[i]-'A']++;
        }
        int ans=0;
        
        for(i=0;i<26;i++)
        {
            if(a[i]%2==0) ans+=a[i],a[i]=0;
            else ans+=a[i]-1,a[i]=1;
        }
        for(i=0;i<26;i++)
        {
            if(b[i]%2==0) ans+=b[i],b[i]=0;
            else ans+=b[i]-1,b[i]=1;
        }
        
        for(i=0;i<26;i++)
        {
            if(a[i]==1) 
            {
                ans++;
                break;
            }
        }
        
        if(ans%2==0)
        {
            for(i=0;i<26;i++)
            {
                if(b[i]==1) 
                {
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};