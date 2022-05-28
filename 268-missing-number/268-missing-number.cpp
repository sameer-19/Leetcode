class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),ans=0,flag=0;
        for(int i=0;i<n;i++)
        {
            if(abs(nums[i])==n)
            {
                flag=1;
            }
            else
            {
                nums[abs(nums[i])]*=-1;
            }
        }
        if(flag==0) return n;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) return i;
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) return i;
        }
        return 0;
    }
};