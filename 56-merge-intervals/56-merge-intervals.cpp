class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        if(a.size()==1) return a;
        
        sort(a.begin(),a.end());
        
        int start=a[0][0],end=a[0][1],i=1;
        
        while(i<a.size())
        {
            if(end>=a[i][0]) end=max(end,a[i][1]);
            else
            {
                vector<int> c;
                c.push_back(start);
                c.push_back(end);
                start=a[i][0];
                end=a[i][1];
                ans.push_back(c);
            }
            i++;
        }
        vector<int> c;
        c.push_back(start);
        c.push_back(end);
        ans.push_back(c);
        return ans;
    }
};