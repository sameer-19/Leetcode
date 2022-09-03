class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        
        int i,j;
        int firstRow=0,firstCol=0;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0) firstRow=1;
                    if(j==0) firstCol=1;
                    
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        if(firstRow)
        {
            for(j=0;j<n;j++) matrix[0][j]=0;
        }
        
        if(firstCol)
        {
            for(i=0;i<m;i++) matrix[i][0]=0;
        }
        
        return;
    }
};