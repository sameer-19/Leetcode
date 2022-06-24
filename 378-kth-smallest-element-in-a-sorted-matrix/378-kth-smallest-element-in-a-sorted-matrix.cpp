class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<int> pq;
        
        int ans=0,i,j,f=0,n=mat.size();
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(pq.size()<k)
                {
                    pq.push(mat[i][j]);
                }
                else
                {
                    if(pq.top()>mat[i][j])
                    {
                        pq.pop();
                        pq.push(mat[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};