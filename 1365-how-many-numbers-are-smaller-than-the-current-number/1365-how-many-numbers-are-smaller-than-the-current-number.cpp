class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        
        int i,j,n=nums.size();
        
        int a[102]={0};
        
        for(auto x: nums) a[x]++;
        
        for(i=1;i<102;i++)
        {
            a[i]+=a[i-1];
        }
        
        for(i=0;i<n;i++)
        {
            if(nums[i]==0) ans.push_back(0);
            else ans.push_back(a[nums[i]-1]);
        }
        
        return ans;
    }
};