class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> ans;
        
        vector<int> res;
        res.push_back(1);
        ans.push_back(res);
        
        if(n==0) return res;
        
        res.push_back(1);
        ans.push_back(res);
        
        if(n==1) return res; 
        
        int i,j;
        
        for(i=3;i<=n+1;i++)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for(j=1;j<=i-2;j++)
            {
                tmp.push_back(res[j]+res[j-1]);
            }
            tmp.push_back(1);
            ans.push_back(tmp);
            res=tmp;
        }
        
        return ans[n];
    }
};