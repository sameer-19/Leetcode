class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans=0;
        
        int n=nums.size();
        
        unordered_map<int,int> mp,all;
        for(auto x: nums) all[x]++;
        
        int left=0,right=0,cnt=0;
        
        while(right<n)
        {
            mp[nums[right]]++;
            while(left<=right and mp.size()==all.size()) {
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
                ans+=n-right;
            }
            
            right++;
        }
        
        return ans;
    }
};