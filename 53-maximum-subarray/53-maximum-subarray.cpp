class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i,ans=INT_MIN,sum=0,n=nums.size();
        
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            
            ans=max(ans,sum);
            
            if(sum<0) sum=0;
        }
        
        return ans;
    }
};