class Solution {
public:
    int countServers(vector<vector<int>>& a) {
        int ans=0;
        int m=a.size(),n=a[0].size();
        
        int i,j,k;
        vector<vector<int>> visited(m,vector<int> (n,0));
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]==1)
                {
                    for(k=0;k<m;k++)
                    {
                        if(i!=k)
                        {
                            if(visited[k][j]==0 and a[k][j]==1) 
                            {
                                ans++;
                                visited[k][j]=1;
                            }
                        }
                    }
                    
                    for(k=0;k<n;k++)
                    {
                        if(k!=j)
                        {
                            if(visited[i][k]==0 and a[i][k]==1)
                            {
                                ans++;
                                visited[i][k]=1;
                            }
                        }
                    }
                    
                }
            }
        }
        
        return ans;
    }
};