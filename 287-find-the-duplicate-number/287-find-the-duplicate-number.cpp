class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int a[100005]={0},i;
        for(i=0;i<nums.size();i++)
        {
            if(a[nums[i]]==0) a[nums[i]]++;
            else return nums[i];
        }
        return nums[0];
    }
};