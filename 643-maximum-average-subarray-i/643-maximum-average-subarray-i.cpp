class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=0;
        int i,n=nums.size(),sum=0;
        
        for(i=0;i<k;i++) sum+=nums[i];
        ans=(double)sum/k;
        
        for(i=k;i<n;i++)
        {
            sum+=nums[i]-nums[i-k];
            ans=max(ans,(double)sum/k);
        }
        
        return ans;
    }
};