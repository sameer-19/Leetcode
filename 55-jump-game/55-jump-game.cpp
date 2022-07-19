class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int n=nums.size(),mx=0,i;
        
        bool flag=0;
        for(i=0;i<n;i++)
        {
            if(i==0) mx=max(mx,nums[i]);
            else
            {
                if(mx>=i)
                {
                    mx=max(mx,i+nums[i]);
                }
                else
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag) return false;
        return true;
    }
};