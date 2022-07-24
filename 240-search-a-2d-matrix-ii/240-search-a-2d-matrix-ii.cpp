class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),r,c;
        
        // start from top right and reduce column and row according to condition
        r=0;c=n-1;
        
        while(r<m and c>=0)
        {
            if(matrix[r][c]==target)
            {
                return true;
            }
            matrix[r][c]>target ? c-- : r++;
        }
        
        // Time Complexity - O(m+n)
        
        return false;
    }
};