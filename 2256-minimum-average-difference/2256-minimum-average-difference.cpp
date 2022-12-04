class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        
        int ans=0,mn=INT_MAX;
        
        vector<long long> pre(n,0),suf(n,0);

        pre[0]=nums[0]; suf[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+nums[i];
        }
        
        for(int i=0;i<n;i++)
        {
            int first = pre[i]/(i+1);
            int second = 0;
            if(i+1<n) second = suf[i+1]/(n-i-1);
            
            int diff = abs(first-second);
            if(mn>diff)
            {
                mn=diff;
                ans=i;
            }
        }
        
        
        return ans;
    }
};