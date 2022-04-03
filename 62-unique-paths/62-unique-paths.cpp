class Solution {
public:
    int uniquePaths(int m, int n) {
        int a[105][105];
        int i,j,ans=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0 || j==0) a[i][j]=1;
            }
        }
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
        ans=a[m-1][n-1];
        return ans;
    }
};