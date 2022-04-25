class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        vector<int> ans;
        vector<int> row,col;
        
        int i,j,k;
        
        int m=mat.size(),n=mat[0].size();
        
//         for(i=0;i<m;i++)
//         {   
//             for(j=0;j<n;j++)
//             {
//                 int mn=INT_MAX,mx=INT_MIN;
                
//                 for(k=0;k<n;k++)
//                 {
//                     mn=min(mat[i][k],mn);
//                 }
                
//                 for(k=0;k<m;k++)
//                 {
//                     mx=max(mat[k][j],mx);
//                 }
                
//                 if(mn==mx) ans.push_back(mn);
//             }
//         }
        
        for(i=0;i<m;i++)
        {
            int mn=INT_MAX,id1=i,id2=0;
            for(j=0;j<n;j++)
            {
                mn=min(mat[i][j],mn);
            }
            row.push_back(mn);
        }
        
        for(i=0;i<n;i++)
        {
            int mx=INT_MIN,id2=i,id1=0;
            for(j=0;j<m;j++)
            {
                mx=max(mat[j][i],mx);
            }
            col.push_back(mx);
        }
        
        sort(col.begin(),col.end());
        
        for(i=0;i<row.size();i++)
        {
            if(binary_search(col.begin(),col.end(),row[i])) ans.push_back(row[i]);
        }
        
        return ans;
        
    }
};