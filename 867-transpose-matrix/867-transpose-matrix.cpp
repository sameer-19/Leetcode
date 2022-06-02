class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        
        int i,j,m=mat.size(),n=mat[0].size();
        
        for(i=0;i<n;i++)
        {
            vector<int> v;
            for(j=0;j<m;j++)
            {
                v.push_back(mat[j][i]);
            }
            ans.push_back(v);
        }

        return ans;
    }
};