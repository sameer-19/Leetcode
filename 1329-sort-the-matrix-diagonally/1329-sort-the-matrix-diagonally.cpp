class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int m=mat.size(),n=mat[0].size(),i,j;
        
        for(i=0;i<n;i++)
        {
            vector<int> tp;
            int x=0,y=i;
            while(x<m and y<n)
            {
                tp.push_back(mat[x][y]);
                x++;
                y++;
            }
            
            sort(tp.begin(),tp.end());
            x=0;y=i;
            int c=0;
            while(x<m and y<n)
            {
                mat[x][y]=tp[c++];
                x++;
                y++;
            }
        }
        
        for(i=1;i<m;i++)
        {
            vector<int> tp;
            int x=i,y=0;
            while(x<m and y<n)
            {
                tp.push_back(mat[x][y]);
                x++;
                y++;
            }
            
            sort(tp.begin(),tp.end());
            x=i;y=0;
            int c=0;
            while(x<m and y<n)
            {
                mat[x][y]=tp[c++];
                x++;
                y++;
            }
        }
        
        return mat;
    }
};