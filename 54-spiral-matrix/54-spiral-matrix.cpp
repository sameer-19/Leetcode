class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int m=matrix.size(),n=matrix[0].size(),i,j;
        
        int top=0,left=0,right=n-1,bottom=m-1;
        
        int direction = 1;
        
        while(left<=right and top<=bottom)
        {
            if(direction==1)
            {
                for(i=left;i<=right;i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                direction=2;
                top++;
            }
            else if(direction==2)
            {
                for(i=top;i<=bottom;i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
                direction=3;
            }
            else if(direction==3)
            {
                for(i=right;i>=left;i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
                direction=4;
            }
            else
            {
                for(i=bottom;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                
                left++;
                
                direction=1;
            }
        }
        
        return ans;
    }
};