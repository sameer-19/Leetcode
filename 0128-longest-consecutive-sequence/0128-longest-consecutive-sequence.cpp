class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto x: nums){
            mp[x]++;
        }
        
        int ans=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            if(mp[nums[i]]>0)
            {
                int cur=nums[i],count=0;
                while(mp[cur]>0)
                {
                    mp[cur]=0;
                    cur++;
                    count++;
                }
                
                cur=nums[i]-1;
                while(mp[cur]>0)
                {
                    mp[cur]=0;
                    cur--;
                    count++;
                }
                
                ans=max(count,ans);
            }
        }
        
        return ans;
    }
};