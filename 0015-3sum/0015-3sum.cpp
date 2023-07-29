class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        set<vector<int>> s;
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int sum=nums[i]+nums[j];
                int target = -sum;
                
                if(mp[target]>0)
                {
                    if(target!=nums[i] and target!=nums[j]) 
                    {
                        vector<int> t = {nums[i],nums[j],target};
                        sort(t.begin(),t.end());
                        s.insert(t);
                    }
                    else if(target==nums[i] and target==nums[j])
                    {
                        if(mp[target]>2) 
                        {
                            vector<int> t = {nums[i],nums[j],target};
                            sort(t.begin(),t.end());
                            s.insert(t);
                        }
                    }
                    else if((target==nums[i] and target!=nums[j]) || (target!=nums[i] and target==nums[j]))
                    {
                        if(mp[target]>1) 
                        {
                            vector<int> t = {nums[i],nums[j],target};
                            sort(t.begin(),t.end());
                            s.insert(t);
                        }
                    }
                }
            }
        }
        
        for(auto x: s) ans.push_back(x);
        
        return ans;
    }
};