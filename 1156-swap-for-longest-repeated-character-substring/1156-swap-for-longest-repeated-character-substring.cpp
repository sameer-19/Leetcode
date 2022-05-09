class Solution {
public:
    int maxRepOpt1(string s) {
        int i,j,n=s.length();
        
        vector<int> a[26];
        
        for(i=0;i<n;i++) a[s[i]-'a'].push_back(i);
        
        int ans=0;
        
        for(i=0;i<26;i++)
        {
            int cur=1,prev=0,sum=0;
            for(j=1;j<a[i].size();j++)
            {
                if(a[i][j]==a[i][j-1]+1) ++cur;
                else
                {
                    prev= (a[i][j]==a[i][j-1]+2) ? cur : 0;
                    cur=1;
                }
                sum=max(sum,cur+prev);
            }
            ans=max(ans,sum+(sum<a[i].size() ? 1 : 0));
        }
        
        return ans;
    }
};