class Solution {
public:
    string pushDominoes(string dom) {
        string ans="";
        
        int i,j,n=dom.length();
        vector<int> v(n,0);
        
        for(i=0;i<n;i++)
        {
            if(dom[i]=='L') v[i]=-1;
            else if(dom[i]=='R') v[i]=1;
        }
        
        for(i=0;i<n;++i)
        {
            if(v[i]==0) continue;
            else if(v[i]==-1)
            {
                j=i-1;
                while(j>=0 and v[j]==0)
                {
                    v[j]=-1;
                    j--;
                }
            }
            else
            {
                j=i+1;
                int cnt=0;
                while(j<n and v[j]==0) 
                {
                    cnt++;
                    j++;
                }
                
                if(j==n)
                {
                    j=i+1;
                    while(j<n)
                    {
                        v[j]=1;
                        j++;
                    }
                    i=j-1;
                    
                    continue;
                }
                
                if(cnt>0)
                {
                    int d = cnt/2;
                    int last=j;
                    
                    if(v[last]==1)
                    {
                        for(j=i+1;j<last;j++) v[j]=1;
                        i=j-1;
                        continue;
                    }
                    
                    for(j=0;j<d;j++)
                    {
                        v[i+1+j]=1;
                    }

                    for(j=0;j<d;j++)
                    {
                        v[last-1-j]=-1;
                    }
                    
                    i=last;
                }
            }
        }
        
        for(i=0;i<n;i++) 
        {
            if(v[i]==0) ans+='.';
            else if(v[i]==1) ans+='R';
            else ans+='L';
        }
        
        return ans;
    }
};