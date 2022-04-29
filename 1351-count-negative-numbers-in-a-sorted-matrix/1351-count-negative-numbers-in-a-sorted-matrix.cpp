class Solution {
public:
    int countNegatives(vector<vector<int>>& a) {
        int cnt=0,i,j;
        
        int m=a.size(),n=a[0].size();
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]<0) cnt++;
            }
        }
        return cnt;
    }
};