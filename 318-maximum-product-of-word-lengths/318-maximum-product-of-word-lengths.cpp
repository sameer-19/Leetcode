class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        
        int i,j,k,n=words.size();
        vector<vector<int>> v(n,vector<int> (26,0));
        
        // for(i=0;i<n;i++)
        // {
        //     for(j=0;j<26;j++) v[i][j]=0;
        // }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<words[i].size();j++) v[i][words[i][j]-'a']++;
        }
        
        for(i=0;i<n;i++)
        {
            int f=0;
            for(j=i+1;j<n;j++)
            {
                f=0;
                for(k=0;k<26;k++)
                {
                    if(v[i][k]>0 and v[j][k]>0)
                    {
                        f=1;
                        break;
                    }
                }
                int len=words[i].size()*words[j].size();
                if(f==0) ans=max(ans,len);
            }   
        }
        
        return ans;
    }
};