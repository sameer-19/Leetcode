class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> b(nums.begin(),nums.end());
        sort(b.begin(),b.end());
        
        int n=nums.size();
        int i=0,j=n-1;
        while(i<n and nums[i]==b[i]) i++;
        while(j>=0 and nums[j]==b[j]) j--;
        return max(0,j-i+1);   
    }
};