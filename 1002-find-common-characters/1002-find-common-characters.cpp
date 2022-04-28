class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        
        int n=words.size();
        
        int i,j,cnt;
        
        int a[105][26];
        memset(a,0,sizeof(a));
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<words[i].length();j++)
            {
                a[i][words[i][j]-'a']++;
            }
        }
        for(j=0;j<26;j++)
        {
            cnt=0;
            int mn=INT_MAX;
            for(i=0;i<n;i++)
            {
                if(a[i][j]>0) 
                {
                    cnt++;
                    mn=min(mn,a[i][j]);
                }
            }
            if(cnt==n) 
            {
                char ch='a';
                ch+=j;
                
                string st="";
                st+=ch;
                
                for(i=0;i<mn;i++) 
                {
                    ans.push_back(st);
                }
                
            }
        }
        
        
        return ans;
    }
};