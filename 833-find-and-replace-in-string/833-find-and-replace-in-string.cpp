class Solution {
public:
    string findReplaceString(string s, vector<int>& ind, vector<string>& sources, vector<string>& targets) {
        string ans="";
        
        int n=ind.size();
        
        int i,j;
        int visited[1000];
        memset(visited,-1,sizeof(visited));
        vector<string> v;
        
        for(i=0;i<n;i++)
        {
            if(s.substr(ind[i],sources[i].length())==sources[i])
            {
                for(j=ind[i];j<ind[i]+sources[i].length();j++)
                {
                    visited[j]=i;
                }
                v.push_back(targets[i]);
                // ans+=sources[i];
            }
        }
        j=0;
        n=s.length();
        int cur=-1;
        for(i=0;i<n;i++)
        {
            if(visited[i]==-1) 
            {
                ans+=s[i]; cur=-1;
            }
            else
            {
                if(cur==visited[i]) continue;
                else
                {
                    ans+=targets[visited[i]];
                    cur=visited[i];
                }
            }
        }
        return ans;
        
    }
};