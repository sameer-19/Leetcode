class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),i,j;
        
        for(i=1;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                {
                    triangle[i][j]+=(j==0 ? triangle[i-1][j] : triangle[i-1][j-1]);
                }
                else
                {
                    triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
                }
            }
        }
        
        int ans=INT_MAX;
        for(i=0;i<n;i++) ans=min(ans,triangle[n-1][i]);
        
        return ans;
    }
};