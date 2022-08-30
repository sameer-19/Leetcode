class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        int i,j;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i>j)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }            
    
        for(i=0;i<n;i++)
        {
            j=0;
            while(j<n/2)
            {
                swap(matrix[i][j],matrix[i][n-j-1]);
                j++;
            }
        }
        
        return;
    }
};