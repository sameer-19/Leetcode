class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        int n=nums.size();
        if(n<=3) return ans;
        
        sort(nums.begin(),nums.end());
            
        int i,j;
        for(i=0;i<=n-4;i++)
        {
            for(j=i+1;j<=n-3;j++)
            {
                int sum=nums[i]+nums[j];
                int ttarget=target-sum;
                int left=j+1,right=n-1;
                while(left<right)
                {
                    if(nums[left]+nums[right]>ttarget) right--;
                    else if(nums[left]+nums[right]<ttarget) left++;
                    else 
                    {
                        vector<int> quad={nums[i],nums[j],nums[left],nums[right]};
                        ans.push_back(quad);
                        while(left<n && nums[left]==quad[2]) left++;
                        while(right>=0 && nums[right]==quad[3]) right--;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]) j++;
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        
        return ans;
    }
};