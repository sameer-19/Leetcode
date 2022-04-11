class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        
        vector<vector<int>> res (m, vector<int> (n, 0));
        
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                int newCol = (j+k)%n;
                
                int countWrapArounds = (j+k)/n;
                
                int newRow = (i+countWrapArounds)%m;
                
                res[newRow][newCol] = grid[i][j];
            }
        }
        return res;
    }
};