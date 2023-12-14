class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        
        vector<vector<int>> ans(m,vector<int> (n,0));
        
        vector<int> rows(m,0),cols(n,0);
        
        for(int i=0;i<m;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) cnt++;
            }
            rows[i] = cnt;
        }
        
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(grid[j][i]==1) cnt++;
            }
            cols[i] = cnt;
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int result = rows[i] + cols[j] - (m-rows[i]) - (n-cols[j]);
                ans[i][j] = result;
            }
        }
        
        return ans;
    }
};