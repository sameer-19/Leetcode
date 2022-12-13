class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        vector<vector<int>> res(n,vector<int> (n,INT_MAX));
        
        if(n==1)
        {
            int ans=INT_MAX;
            for(int i=0;i<n;i++)
            {
                ans=min(ans,matrix[0][i]);
            }
            
            return ans;
        }
        
        for(int i=n-1;i>=1;i--)
        {
            for(int j=0;j<n;j++)
            {
                int cur = matrix[i][j];
                if(i!=n-1)
                {
                    cur+=res[i][j];
                }
                
                if(j-1>=0)
                {
                    res[i-1][j-1]=min(res[i-1][j-1],cur);
                }

                res[i-1][j]=min(res[i-1][j],cur);

                if(j+1<n)
                {
                    res[i-1][j+1]=min(res[i-1][j+1],cur);
                }
            }
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            ans=min(ans,res[0][i]+matrix[0][i]);
        }
        
        return ans;
    }
};