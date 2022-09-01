class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        
        for(int i=0;i<n;i++) mp[nums[i]]++;
        
        int c=1;
        
        while(mp[c]>0)
        {
            c++;
        }
        
        return c;
    }
};