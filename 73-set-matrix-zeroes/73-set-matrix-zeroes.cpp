class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        
        int i,j;
        int flag=0;
        
        set<int> row,col;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for(auto x: row)
        {
            for(j=0;j<n;j++) matrix[x][j]=0;
        }
        
        for(auto x: col)
        {
            for(i=0;i<m;i++) matrix[i][x]=0;
        }
        
        return;
    }
};