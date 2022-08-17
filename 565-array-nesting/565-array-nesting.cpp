class Solution {
public:
    void dfs(int i,vector<int> &nums,int &cnt)
    {
        if(nums[i]==-1) return;
        
        cnt++;
        int m = nums[i];
        nums[i]=-1;
        
        dfs(m,nums,cnt);
        
    }
    
    int arrayNesting(vector<int>& nums) {
        int ans=0,cnt=0,n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=-1)
            {
                dfs(i,nums,cnt);
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        
        return ans;
    }
};