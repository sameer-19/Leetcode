class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        
        int n=nums.size(), cnt = 1,prev = -1;
        
        for(int i=0;i<n;i++)
        {
            if((i+1)%3==0)
            {
                if((nums[i]-nums[i-1])<=k)
                {
                    res.push_back(nums[i]);
                }
                else
                {
                    return {};
                }
                
                if((nums[i]-prev)<=k) 
                {
                    ans.push_back(res);
                }
                else
                {
                    return {};
                }
                
                vector<int> tmp;
                res = tmp;
                prev = -1;
            }
            else
            {
                if(prev==-1) 
                {
                    res.push_back(nums[i]);
                    prev = nums[i];
                }
                else
                {
                    if((nums[i]-nums[i-1])<=k)
                    {
                        res.push_back(nums[i]);
                    }
                    else
                    {
                        return {};
                    }
                }
            }
        }
        
        return ans;
    }
};