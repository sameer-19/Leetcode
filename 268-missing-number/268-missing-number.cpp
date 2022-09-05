class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        
        int xor1=nums[0];
        
        for(int i=1;i<n;i++)
        {
            xor1^=nums[i];
        }
        
        for(int i=0;i<=n;i++) xor1^=i;
        
        return xor1;
    }
};