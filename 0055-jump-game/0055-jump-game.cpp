class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int cur=0;
        
        for(int i=0;i<n;i++)
        {
            if(cur<i) return false;
            if(cur>=n-1) return true;
            cur=max(cur,i+nums[i]);
        }
        if(cur>=n-1) return true;
        return false;
    }
};