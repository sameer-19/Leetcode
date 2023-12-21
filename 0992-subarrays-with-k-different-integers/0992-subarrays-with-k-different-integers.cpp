class Solution {
public:
    int subarraysWithAtmostKDistinct(vector<int> &nums,int k)
    {
        int left = 0, right = 0;
        
        int ans=0, n=nums.size();
        
        map<int,int> mp;
        
        while(right<n)
        {
            mp[nums[right]]++;
            
            while(mp.size()>k)
            {
                int count = mp[nums[left]];
                if(count==1) mp.erase(nums[left]);
                else mp[nums[left]]--;
                left++;
            }
            
            ans+=right-left;
            
            right++;
        }
        
        return ans;
    }
        
        
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans1 = subarraysWithAtmostKDistinct(nums,k);
        int ans2 = subarraysWithAtmostKDistinct(nums,k-1);
        
        return ans1-ans2;
    }
};