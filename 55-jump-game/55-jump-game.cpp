class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if(nums.size()==1) return true;
        
        bool possible=false;
        int mx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0) mx=max(mx,nums[i]);
            else
            {
                if(mx>=i)
                {
                    mx=max(mx,nums[i]+i);
                }
                else 
                {
                    possible=false;
                    break;
                }
            }
            if(mx>=nums.size()-1) 
            {
                possible=true;
                break;
            }
        }
        return possible;
    }
};