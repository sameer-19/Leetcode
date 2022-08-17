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
        int ans=0,cnt=0,i,j,n=nums.size();
        
        for(i=0;i<n;i++)
        {
            if(nums[i]!=-1)
            {
                cnt=0;
                j=i;
                while(nums[j]>=0)
                {
                    cnt++;
                    int m=nums[j];
                    nums[j]=-1;
                    j=m;
                }
                ans=max(ans,cnt);
            }
        }
        
        return ans;
    }
};