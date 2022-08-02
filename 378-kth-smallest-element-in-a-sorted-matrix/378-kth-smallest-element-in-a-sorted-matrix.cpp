class Solution {
public:
    int count(vector<vector<int>>& matrix,int x)
    {
        int n=matrix.size();
        
        int row=0,col=n-1,cnt=0;
        
        while(row<n and col>=0)
        {
            if(matrix[row][col]<=x) cnt+=(col+1);
            else
            {
                while(col>=0 and matrix[row][col]>x) col--;
                cnt+=(col+1);
            }
            row++;
        }
        
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        
        int n=matrix.size(),i,j,left=matrix[0][0],right=matrix[n-1][n-1];
        
        int ans=INT_MAX;
        
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(count(matrix,mid)>=k)
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        
        return ans;
    }
};