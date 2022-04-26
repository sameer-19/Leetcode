class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& a) {
        int row[60]={0},col[60]={0};
        
        int ans=0;
        int i,sz=a.size();
        
        for(i=0;i<sz;i++)
        {
            row[a[i][0]]++;
            col[a[i][1]]++;
        }
        
        int even_col=0,odd_col=0,even_row=0,odd_row=0;
        
        for(i=0;i<m;i++) {
            if(row[i]%2==0) even_row++;
            else odd_row++;
        }
        
        for(i=0;i<n;i++) {
            if(col[i]%2==0) even_col++;
            else odd_col++;
        }
        
        return (even_row*odd_col)+(odd_row*even_col);
        
    }
};