class Solution {
public:
    string countAndSay(int n) {
        string s[32];
        s[1]="1";
        int i,j;
        
        for(i=2;i<=n;i++)
        {
            int cnt=0;
            for(j=0;j<s[i-1].length();j++)
            {
                if(j==0) cnt++;
                else
                {
                    if(s[i-1][j]==s[i-1][j-1])
                    {
                        cnt++;
                        continue;
                    }
                    s[i]+=to_string(cnt);
                    s[i]+=s[i-1][j-1];
                    cnt=1;
                }
            }
            if(cnt>0)
            {
                s[i]+=to_string(cnt);
                s[i]+=s[i-1][j-1];
                cnt=0;
            }
        }
        
        return s[n];
    }
};