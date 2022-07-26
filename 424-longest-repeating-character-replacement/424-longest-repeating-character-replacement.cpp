class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        
        int i,j,n=s.length(),ans=0;
        
        int mxcharCount = 0;
        int start=0,end;
        
        for(end=0;end<n;end++)
        {
            count[s[end]-'A']++;
            if(mxcharCount < count[s[end]-'A'])
            {
                mxcharCount=count[s[end]-'A'];
            }
            
            while(end-start-mxcharCount+1>k)
            {
                count[s[start]-'A']--;
                start++;
                for(i=0;i<26;i++)
                {
                    if(mxcharCount<count[i]) mxcharCount = count[i];
                }
            }
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};