class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int m=matrix.size(),n=matrix[0].size(),i,j;
        
        int top=0,left=0,right=n-1,bottom=m-1;
        
        int direction = 1;
        
        vector<vector<bool>> visited(m+1,vector<bool> (n+1,false));
        
        while(left<=right and top<=bottom)
        {
            for(i=left;i<=right;i++)
            {
                if(!visited[top][i]) ans.push_back(matrix[top][i]),visited[top][i]=true;
            }
            top++;

            for(i=top;i<=bottom;i++)
            {
                if(!visited[i][right]) ans.push_back(matrix[i][right]),visited[i][right]=true;
            }
            right--;

            for(i=right;i>=left;i--)
            {
                if(!visited[bottom][i]) ans.push_back(matrix[bottom][i]),visited[bottom][i]=true;
            }
            bottom--;

            for(i=bottom;i>=top;i--)
            {
                if(!visited[i][left]) ans.push_back(matrix[i][left]),visited[i][left]=true;
            }

            left++;
        }
        
        return ans;
    }
};