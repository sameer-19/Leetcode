class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int i;
        unordered_set<int> s;
        int ans=0;
        
        for(auto x: nums) s.insert(x);
        
        for(auto x: nums)
        {
            if(!s.count(x-1))
            {
                int cur=x;
                int cnt=1;
                while(s.count(cur+1)){
                    cur++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};