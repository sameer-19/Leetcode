class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,i,n=nums.size();
        
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        int prevSum=0;
        
        for(i=0;i<n;i++)
        {
            if(prevSum==sum-nums[i])
            {
                return i;
            }
            
            prevSum+=nums[i];
            sum-=nums[i];
        }
        
        return -1;
    }
};