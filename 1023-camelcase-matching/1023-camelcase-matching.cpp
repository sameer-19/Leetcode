class Solution {
public:
    vector<bool> camelMatch(vector<string>& q, string pat) {
        int lower[26]={0},upper[26]={0};
        
        int n=q.size(),m=pat.length(),i,j;
        
        for(i=0;i<m;i++)
        {
            if(pat[i]>='A' and pat[i]<='Z') upper[pat[i]-'A']++;
            else lower[pat[i]-'a']++;
        }
        
        vector<bool> v(n);
        
        for(i=0;i<n;i++)
        {
            int low[26]={0},up[26]={0},f=0;
            
            for(j=0;j<q[i].size();j++)
            {
                if(q[i][j]>='A' and q[i][j]<='Z') up[q[i][j]-'A']++;
                else low[q[i][j]-'a']++;
            }
            
            for(j=0;j<26;j++)
            {
                if(upper[j]!=up[j]) 
                {
                    f=1;break;
                }
            }
            
            int k=0,l=0;
            while(k<q[i].size() and l<m)
            {
                if(q[i][k]==pat[l]) {k++; l++;}
                else k++;
            }
            
            if(l!=m) f=1;
            
            if(f==0) v[i]=true;
            else v[i]=false;
            
            
        }
        
        return v;
    }
};