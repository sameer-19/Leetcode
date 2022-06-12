class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),i;
        int ans=0;
    
        unordered_map<int,int> mp;
        
        int left=0,sum=0;
        i=0;
        
        
        while(i<n)
        {
            sum+=nums[i];
            mp[nums[i]]++;
            while(mp[nums[i]]>1)
            {
                mp[nums[left]]--;
                sum-=nums[left];
                left++;
            }
            
            ans=max(ans,sum);
            i++;
        }
        
        return ans;
    }
};