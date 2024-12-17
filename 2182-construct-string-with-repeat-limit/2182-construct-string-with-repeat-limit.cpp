class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int a[26] = {0}, n=s.size(), cnt = 0, j = 24;
        for(int i=0;i<n;i++) a[s[i]-'a']++;
        
        string ans = "";
        for(int i=25;i>=0;i--)
        {
            while(a[i]>0 and j>=0) 
            {
                char ch = 'a'+i;
                while(a[i]>0 and cnt<repeatLimit)
                {
                    ans+=ch;
                    a[i]--;
                    cnt++;
                }
                
                if(a[i]==0) cnt=0;
                else
                {
                    j=i-1;
                    while(j>=0 and a[j]==0) j--;
                    if(j>=0 and a[j]>0)
                    {
                        char ch = 'a'+j;
                        a[j]--;
                        ans +=ch;
                        cnt = 0;
                    }
                }
            }
            // cout<<ans<<" "<<cnt<<"\n";
        }
        
        return ans;
    }
};