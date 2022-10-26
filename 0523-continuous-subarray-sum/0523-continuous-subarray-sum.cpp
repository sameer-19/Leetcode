class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0,n=nums.size(),i;
        if(n==1) return false;
        
        unordered_map<int,int> mp;
        mp[0]=0;
        
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.find(sum%k)==mp.end())
            {
                mp[sum%k]=i+1;
            }
            
            if(mp[sum%k]<i) return true;
        }
        
        return false;
    }
};