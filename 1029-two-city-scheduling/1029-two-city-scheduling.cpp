class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return (a[1]-a[0])>(b[1]-b[0]);   
    }
    
    int twoCitySchedCost(vector<vector<int>>& a) {
        int ans=0,i,n=a.size();
        sort(a.begin(),a.end(),cmp);
        for(i=0;i<n;i++)
        {
            ans+=(i>=n/2) ? a[i][1] : a[i][0];
        }
        return ans;
        
    }
};