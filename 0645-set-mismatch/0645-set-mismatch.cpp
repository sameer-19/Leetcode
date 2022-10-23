class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup=-1,missing=-1;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1]<0) dup=abs(nums[i]);
            else 
            {
                nums[abs(nums[i])-1]*=-1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) missing = i+1;
        }
        
        return {dup,missing};
    }
};