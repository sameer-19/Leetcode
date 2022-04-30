class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int cnt=0,i;
        for(auto x: nums)
        {
            if(x==1) cnt++;
            else{
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        ans=max(cnt,ans);
        return ans;
    }
};