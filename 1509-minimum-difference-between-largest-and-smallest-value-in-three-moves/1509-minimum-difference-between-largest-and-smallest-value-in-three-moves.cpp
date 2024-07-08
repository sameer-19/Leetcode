class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        if(n<=3) return 0;
        
        int ans = INT_MAX;

        int firstThree, lastThree, firstTwo, lastTwo;
        firstThree = nums[n-1] - nums[3];
        lastThree = nums[n-4] - nums[0];
        firstTwo = nums[n-2] - nums[2];
        lastTwo = nums[n-3] - nums[1];
        
        ans = min({firstThree,lastThree,firstTwo,lastTwo});
        
        return ans;
    }
};