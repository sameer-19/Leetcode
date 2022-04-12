class Solution {
public:
    void gameOfLife(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size(),i,j;
        
        vector<vector<int>> ans(m,vector<int> (n,0));
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                int cnt=0;
                
                if(i+1<m)
                {
                    if(a[i+1][j]==1) cnt++;
                    
                    if(j+1<n && a[i+1][j+1]==1) cnt++;
                    
                    if(j-1>=0 && a[i+1][j-1]==1) cnt++;
                }
                if(j+1<n)
                {
                    if(a[i][j+1]==1) cnt++;
                }
                if(j-1>=0)
                {
                    if(a[i][j-1]==1) cnt++;
                }
                if(i-1>=0)
                {
                    if(a[i-1][j]==1) cnt++;
                    
                    if(j+1<n && a[i-1][j+1]==1) cnt++;
                    
                    if(j-1>=0 && a[i-1][j-1]==1) cnt++;
                }
                
                if(a[i][j]==1)
                {
                    if(cnt<2) ans[i][j]=0;
                    else if(cnt==2 || cnt==3) ans[i][j]=1;
                    else ans[i][j]=0;
                }
                else
                {
                    if(cnt==3) ans[i][j]=1;
                }
            }
        }
        
        a=ans;
    }
};