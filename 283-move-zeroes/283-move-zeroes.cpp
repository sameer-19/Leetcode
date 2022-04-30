class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j,n=nums.size();
        i=0;j=0;
        while(i<n && j<n)
        {
            if(nums[i]==0 && nums[j]!=0)
            {
                swap(nums[i],nums[j]);
                i++;j++;
            }
            else if(nums[i]!=0 && nums[j]==0) continue;
            else if(nums[i]==0 && nums[j]==0) j++;
            else {i++;j++;}
        }
        return;
    }
};