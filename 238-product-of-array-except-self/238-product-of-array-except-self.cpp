class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),i,cnt=0;
        
        vector<int> ans;
        
        for(i=0;i<n;i++)
        {
            if(nums[i]==0) cnt++;
        }
        
        if(cnt>1)
        {
            for(i=0;i<n;i++)
            {
                ans.push_back(0);
            }
        }
        else if(cnt==1)
        {
            int product=1;
            for(i=0;i<n;i++)
            {
                if(nums[i]!=0) product*=nums[i];
            }
            for(i=0;i<n;i++)
            {
                if(nums[i]==0) ans.push_back(product);
                else
                {
                    ans.push_back(0);
                }
            }
        }
        else
        {
            int product=1;
            for(i=0;i<n;i++)
            {
                product*=nums[i];
            }
            for(i=0;i<n;i++)
            {
                ans.push_back(product/nums[i]);
            }
        }
        
        return ans;
    }
};