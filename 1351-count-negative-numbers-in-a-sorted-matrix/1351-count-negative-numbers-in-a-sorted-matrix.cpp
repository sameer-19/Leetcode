class Solution {
public:
    int countNegatives(vector<vector<int>>& a) {
        int cnt=0,i,j;
        
        int m=a.size(),n=a[0].size();
        
        for(i=0;i<m;i++)
        {
            int low=0,high=n-1;
            int x=INT_MAX;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(a[i][mid]<0) 
                {
                    x=min(x,mid);
                    high=mid-1;
                }
                else low=mid+1;
            }
            if(x!=INT_MAX) cnt+=n-x;
        }
        return cnt;
    }
};