class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        
        int i,j,k;
        // first row traversal
        for(i=0;i<n;i++)
        {
            j=0,k=i;
            while(j<m and k<n)
            {
                if(matrix[j][k]!=matrix[0][i]) return false;
                j++;
                k++;
            }
        }        
        
        // first column traversal
        for(i=1;i<m;i++)
        {
            j=i;k=0;
            while(j<m and k<n)
            {
                if(matrix[j][k]!=matrix[i][0]) return false;
                j++;
                k++;
            }
        }
        
        return true;
    }
};
