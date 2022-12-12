class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        
        int i,mn,n=points.size();
        
        for(i=1;i<n;i++)
        {
            mn=min(abs(points[i][0]-points[i-1][0]),abs(points[i][1]-points[i-1][1]));
            ans+=mn;
            if(abs(points[i][0]-points[i-1][0])!=mn) ans+=abs(points[i][0]-points[i-1][0])-mn;
            if(abs(points[i][1]-points[i-1][1])!=mn) ans+=abs(points[i][1]-points[i-1][1])-mn;
        }
        
        return ans;   
    }
};