class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int idx=matrix.size()-1;
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]<=target && matrix[i][matrix[0].size()-1]>=target)
            {
                idx=i;
                break;
            }
        }
        int left=0,right=matrix[0].size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(target==matrix[idx][mid]) return true;
            else if(target<matrix[idx][mid]) right=mid-1;
            else left=mid+1;
        }
        // for(int i=0;i<matrix[0].size();i++) 
        // {
        //     if(target==matrix[idx][i]) return true;
        // }
        return false;
    }
};