class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        
        int curMax=1,curMin=1;
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++) ans=max(ans,nums[i]);
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                curMax=1;curMin=1;
                continue;
            }
            else
            {
                int prod1=curMax*nums[i],prod2=curMin*nums[i];
                
                curMax=max({prod1,prod2,nums[i]});
                curMin=min({prod1,prod2,nums[i]});
                
                ans=max(ans,curMax);
            }
        }
        
        return ans;
    }
};