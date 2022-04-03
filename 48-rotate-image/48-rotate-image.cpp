class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat[0].size();
        int i,j;
        // first calculate transpose of a matrix
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i>j)
                {
                    swap(mat[i][j],mat[j][i]);
                }
            }
        }
        // reverse each row once you found the transpose to get the rotation
        for(i=0;i<n;i++)
        {
            for(j=0;j<n/2;j++) swap(mat[i][j],mat[i][n-j-1]);
        }
        return;    
    }
};