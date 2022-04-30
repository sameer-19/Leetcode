class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n=nums.size(),first,second;
        int i=0,j=n-1,k=n-1;
        vector<int> ans(n);
        
        while(i<=j)
        {
            first=nums[i]*nums[i];
            second=nums[j]*nums[j];
            if(second>=first) 
            {
                ans[k--]=second;
                j--;
            }
            else{
                ans[k--]=first;
                i++;
            }
        }
        return ans;
    }
};