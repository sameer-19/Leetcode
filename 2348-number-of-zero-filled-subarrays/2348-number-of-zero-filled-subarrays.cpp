class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        
        int cnt=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                ans+=((long long)(cnt+1)*cnt)/2;
                cnt=0;
            }
            else cnt++;
        }
        
        if(cnt!=0) ans+=((long long)cnt*(cnt+1))/2;
        
        return ans;
    }
};