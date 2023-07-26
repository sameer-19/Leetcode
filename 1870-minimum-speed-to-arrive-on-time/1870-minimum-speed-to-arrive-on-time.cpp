class Solution {
public:
    bool check(int mid,vector<int>&dist, double hour)
    {
        double sum=0;
        
        for(int i=0;i<dist.size();i++)
        {
            double cur = (double)dist[i]/mid;
            sum+=cur;
            if(i<(dist.size())-1) sum = ceil(sum/1.0);
        }
        
        return (sum<=hour);
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans=-1;
        
        int low=1,high=1e8,mid;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid,dist,hour))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
    }
};