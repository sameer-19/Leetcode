class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& a) {
        int i,j;
        int m=a.size(),n=a[0].size();
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0 || j==0) continue;
                else if(a[i][j]!=a[i-1][j-1]) return false;
            }
        }
        return true;
    }
};