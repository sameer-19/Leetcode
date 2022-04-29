class Solution {
public:
    int distanceBetweenBusStops(vector<int>& a, int start, int dest) {
        int i,ans=INT_MAX,sum=0,n=a.size();
        
        if(start>dest) swap(start,dest);
        
        for(i=start;i<min(n,dest);i++)
        {
            sum+=a[i];
        }
        
        ans=min(ans,sum);
        sum=0;
        
        for(i=dest;i<n;i++) sum+=a[i];
        
        for(i=0;i<start;i++) sum+=a[i];
        
        ans=min(ans,sum);
        
        return ans;
    }
};