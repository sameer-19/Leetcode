class Solution {
public:
    int calculate(vector<int> &a,vector<int> &b)
    {
        int xD = abs(a[0]-b[0]), yD = abs(a[1]-b[1]);
        int res = min(xD,yD);
        xD-=res; yD-=res;
        res+=xD; res+=yD;
        return res;
    }
        
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        
        for(int i=1;i<points.size();i++)
        {
            ans+= calculate(points[i-1],points[i]);
        }
        
        return ans;
    }
};