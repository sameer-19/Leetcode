class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,ans;
        for(auto x: nums)
        {
            if(cnt==0)
            {
                ans=x;
            }
            cnt+=(ans==x) ? 1 : -1;
        }
        return ans;
    }
};