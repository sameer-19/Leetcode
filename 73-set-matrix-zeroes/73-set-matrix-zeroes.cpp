class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        set<int> row,col;
        int m=mat.size(),n=mat[0].size();
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(mat[i][j]==0) {row.insert(i);col.insert(j);}
            }
        }
        for(auto x: row)
        {
            for(j=0;j<n;j++) mat[x][j]=0;
        }
        for(auto x: col) 
        {
            for(i=0;i<m;i++) mat[i][x]=0;
        }
        return;
    }
};