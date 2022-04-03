class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        vector<int> row,col;
        int m=mat.size(),n=mat[0].size();
        int i,j,col0=1;
        for(i=0;i<m;i++)
        {
            if(mat[i][0]==0) col0=0;
            for(j=1;j<n;j++)   
            {
                if(mat[i][j]==0)
                {
                    mat[i][0]=mat[0][j]=0;
                }
            }
        }
        
        for(i=m-1;i>=0;i--)
        {
            for(j=n-1;j>=1;j--)
            {
                if(mat[i][0]==0 || mat[0][j]==0) mat[i][j]=0;
            }
            if(col0==0) mat[i][0]=0;
        }
        
        return;
    }
};