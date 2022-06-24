class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size(),n=mat[0].size();
        
        int i,j,idx1=0,idx2=0;
        int left,right;
        
        for(i=0;i<m;i++)
        {
            if(mat[i][0]<=target and mat[i][n-1]>=target)
            {
                left=0;right=n-1;
                idx1=i;
        
                while(left<=right)
                {
                    int mid=left+(right-left)/2;
                    if(mat[idx1][mid]==target) return true;
                    else if(mat[idx1][mid]>target) right=mid-1;
                    else left=mid+1;
                }   
            }
        }
        
        for(j=0;j<n;j++)
        {
            if(mat[0][j]<=target and mat[m-1][j]>=target)
            {
                left=0;right=m-1;
                idx2=j;
        
                while(left<=right)
                {
                    int mid=left+(right-left)/2;
                    if(mat[mid][idx2]==target) return true;
                    else if(mat[mid][idx2]>target) right=mid-1;
                    else left=mid+1;
                }
            }
        }
        
        return false;
    }
};