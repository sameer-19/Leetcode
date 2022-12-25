class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        
        int n=nums.size(),m=queries.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<n;i++) nums[i]+=nums[i-1];
        
        for(int i=0;i<m;i++)
        {
            auto x = lower_bound(nums.begin(),nums.end(),queries[i]) - nums.begin();
            
            if(x==n)
            {
                ans.push_back(x);
            }
            else
            {
                if(nums[x]>queries[i]) ans.push_back(x);
                else ans.push_back(x+1);
            }
        }
        
        return ans;
    }
};