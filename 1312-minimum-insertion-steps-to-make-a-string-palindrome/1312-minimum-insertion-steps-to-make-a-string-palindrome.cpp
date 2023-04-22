class Solution {
public:
    int lcs(string s,string t)
    {
        int len1=s.length(),len2=t.length();
        
        vector<int> prev(len2+1,0),cur(len2+1,0);
        
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(s[i-1]==t[j-1]) cur[j]=1+prev[j-1];
                else cur[j]=max(cur[j-1],prev[j]);
            }
            prev=cur;
        }
        
        return prev[len2];
    }
    
    int minInsertions(string s) {
        int len = s.length();
        
        string t=s;
        reverse(t.begin(),t.end());
        
        return len-lcs(s,t);
    }
};