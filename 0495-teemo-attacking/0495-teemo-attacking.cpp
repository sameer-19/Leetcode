class Solution {
public:
    int findPoisonedDuration(vector<int>& time, int duration) {
        int ans=0;
        
        int n=time.size();
        
        if(n==1) return duration;
        
        for(int i=1;i<n;i++)
        {
            if(time[i-1]+duration-1<time[i]) ans+=duration;
            else
            {
                ans+=time[i]-time[i-1];
            }
        }
        ans+=duration;
        
        return ans;
    }
};