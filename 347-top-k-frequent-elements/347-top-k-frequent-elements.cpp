class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            unordered_map<int, int> mp;

            int i, j, n = nums.size();

            for (i = 0; i < n; i++)
            {
                mp[nums[i]]++;
            }

            vector<vector<int>> v(n+1);
            
            for(auto x: mp){
                v[x.second].push_back(x.first);
            }
            
            vector<int> ans;
            
            for(i=n;i>=0;i--)
            {
                if(k==0) break;
                for(auto x: v[i])
                {
                    if(k==0) break;
                    ans.push_back(x);
                    k--;
                }
            }
            
            return ans;
        }
};