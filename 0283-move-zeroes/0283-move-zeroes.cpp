class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0,right=0;
        int n=nums.size();
        
        while(left<n){
            if(nums[left]!=0) { left++; right++;}
            else
            {
                while(right<n and nums[right]==0) right++;
                if(right<n) { nums[left]=nums[right]; nums[right]=0;}
                left++;
            }
        }
    }
};