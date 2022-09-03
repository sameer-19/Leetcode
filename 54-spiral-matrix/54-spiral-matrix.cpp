class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int m=matrix.size(),n=matrix[0].size(),i,j;
        
        int dir=1;
        
        int top=0,bottom=m-1,left=0,right=n-1;
        
        while(top<=bottom and left<=right)
        {
            if(dir==1)
            {
                for(i=left;i<=right;i++)
                {
                    ans.push_back(matrix[top][i]);   
                }
                top++;
                dir=2;
            }
            else if(dir==2)
            {
                for(i=top;i<=bottom;i++)
                {
                    ans.push_back(matrix[i][right]);   
                }
                right--;
                dir=3;
            }
            else if(dir==3)
            {
                for(i=right;i>=left;i--)
                {
                    ans.push_back(matrix[bottom][i]);   
                }
                bottom--;
                dir=4;
            }
            else
            {
                for(i=bottom;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
                dir=1;
            }
        }
        
        return ans;
    }
};