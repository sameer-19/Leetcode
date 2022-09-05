class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i,j;
        set<int> s;
        for(auto x: nums) s.insert(x);
        
        nums.clear();
        for(auto x: s) nums.push_back(x);
        
        int n=nums.size();
        vector<bool> visited(n,false);
    
        int ans=0;    
        
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                visited[i]=true;
                j=i+1;
                while(j<n and nums[j]==nums[j-1]+1)
                {
                    visited[j]=true;
                    j++;
                }
                
                ans=max(ans,j-i);
            }
        }
        
        return ans;
    }
};