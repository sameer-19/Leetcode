class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int ans=-1e9,n=nums.size(),distance = INT_MAX;
        
        for(int i=0;i<n-2;i++)
        {
            int left=i+1,right=n-1;
            int sum,tmptarget=target-nums[i];
            
            while(left<right)
            {
                sum = nums[left] + nums[right];
                int d = abs(target-sum-nums[i]);
                
                if(sum==tmptarget) 
                {
                    ans=target;
                    break;
                }
                else if(sum<tmptarget)
                {
                    if(distance>d)
                    {
                        distance = d;
                        ans=sum + nums[i];
                    }
                    left++;
                }
                else
                {
                    if(distance>d)
                    {
                        distance = d;
                        ans=sum+nums[i];
                    }
                    right--;
                }
            }
        }
        
        return ans;
    }
};