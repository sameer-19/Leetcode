class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        
        int i,n=a.size();
        
        sort(a.begin(),a.end());
        
        // ans.push_back(a[0]);
        
        int start=a[0][0],end=a[0][1];
        
        for(i=1;i<n;i++)
        {
            if(end<a[i][0])
            {
                ans.push_back({start,end});
                start=a[i][0];
                end=a[i][1];
            }
            else
            {
                end=max(end,a[i][1]);
            }
        }
        
        ans.push_back({start,end});
        
        return ans;
    }
};