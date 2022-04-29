class Solution {
public:
    int countNegatives(vector<vector<int>>& a) {
        int cnt=0;
        
        int m=a.size(),n=a[0].size();
        
        int row=0,col=n-1;
        
        while(row<m)
        {
            while(col>=0 && a[row][col]<0) col--;
            cnt+=n-col-1;
            row++;
        }
        
        return cnt;
    }
};