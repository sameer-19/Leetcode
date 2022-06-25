class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i,n=nums.size();
        
        vector<int> v;
        
        for(i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1]) v.push_back(i);
        }
        
        if(v.size()>=2) return false;
        else if(v.size()==0) return true;
        else // v.size()==1
        {
            if(v[0]==0) return true;
            else
            {
                if(nums[v[0]-1]<=nums[v[0]+1]) return true;
                int id=0;
                for(int i=1;i<n;i++)
                {
                    if(nums[i-1]>nums[i]) { id=i;break; }
                }
                if(id==n-1) return true;
                if(nums[id-1]<=nums[id+1]) return true;
                return false;
            }  
        }
        
        return true;
    }
};