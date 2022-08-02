class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        
        int n=matrix.size(),i,j;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(pq.size()<k) pq.push(matrix[i][j]);
                else
                {
                    if(pq.top()>matrix[i][j])
                    {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        
        return pq.top();
    }
};