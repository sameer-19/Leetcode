class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int countOfNegatives = 0, mn = 1e7;
        long long ans = 0;
        
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                countOfNegatives += matrix[i][j] < 0;
                ans+=abs(matrix[i][j]);
                mn= min(mn, abs(matrix[i][j]));
            }
        }
        
        if(countOfNegatives%2==0)
        {
            return ans;
        }
        
        return ans - (2*mn);
    }
};