class Solution {
public:
    int findPoisonedDuration(vector<int>& time, int duration) {
        int ans=0;
        
        int i=1,n=time.size(),start=time[0],end=time[0]+duration-1;
        
        while(i<n)
        {
            if(time[i]>end)
            {
                ans+=(end-start+1);
                start=time[i];
                end=time[i]+duration-1;
            }
            else {
                end=max(end,time[i]+duration-1);
            }
            i++;
        }
        ans+=(end-start+1);
        
        return ans;
    }
};