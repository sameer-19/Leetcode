class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i,j;
        map<int,int> mp;
        
        int n=nums.size();
        
        for(i=0;i<n;i++) mp[nums[i]]++;
        
        int ans=0,cnt=0;
        
        for(auto x: mp)
        {
            if(mp[x.first-1]>0) continue;
            else
            {
                j=x.first;
                cnt=0;
                while(mp[j]>0) 
                {
                    j++;
                    cnt++;
                }
                
                ans=max(ans,cnt);
            }
        }

        return ans;
    }
};