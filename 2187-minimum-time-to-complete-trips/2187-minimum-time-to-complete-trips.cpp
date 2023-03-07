class Solution {
public:
    long long solve(long long x,vector<int> &time)
    {
        long long count=0;
        
        for(auto &y: time)
        {
            count+=(long long)(x/y);
            if(count>=1e10) return count;
        }
        
        return count;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1, right=1e18,ans=0;
        
        while(left<=right)
        {
            long long mid = left +(right-left)/2;
            
            long long check = solve(mid,time);
           
            if(check>=totalTrips)
            {
                ans = mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        
        return ans;
    }
};