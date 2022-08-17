class Solution {
public:
    void dfs(int i,vector<int> &nums,vector<bool> &visited,int &cnt)
    {
        if(visited[i]==true) return;
        
        cnt++;
        visited[i]=true;
        
        dfs(nums[i],nums,visited,cnt);
        
    }
    
    int arrayNesting(vector<int>& nums) {
        int ans=0,cnt=0,n=nums.size();
        
        vector<bool> visited(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfs(i,nums,visited,cnt);
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        
        return ans;
    }
};