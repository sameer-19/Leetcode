class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        
        int i,j,n=nums.size();
        
        for(i=0;i<n;i++)
        {
            int cnt=0;
            for(j=0;j<n;j++)
            {
                if(i!=j and nums[j]<nums[i]) cnt++;
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};