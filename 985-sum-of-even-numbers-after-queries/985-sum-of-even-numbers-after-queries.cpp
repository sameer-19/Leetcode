class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0,n=nums.size(),q=queries.size();
        
        vector<int> ans(q);
        
        int i,j;
        
        for(i=0;i<n;i++)
        {
            if((nums[i]&1)==0) sum+=nums[i];
        }
        
        for(i=0;i<q;i++)
        {
            int val = queries[i][0];
            int idx = queries[i][1];
            
            if((nums[idx]&1)==0)
            {
                sum-=nums[idx];
            }
            
            nums[idx]+=val;
            if((nums[idx]&1)==0) sum+=nums[idx];
            
            ans[i]=sum;
        }
        
        return ans;
    }
};