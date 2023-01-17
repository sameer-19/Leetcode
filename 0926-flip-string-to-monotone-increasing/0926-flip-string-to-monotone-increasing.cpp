class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.length(),now=0;
        int ones=count(s.begin(),s.end(),'1');
        int ans=min(ones,n-ones);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') now++;
            int curr=now+((n-i-1)-(ones-now));
            ans=min(ans,curr);
        }
        return ans;
    }
};