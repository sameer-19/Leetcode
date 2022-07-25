class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans(2,-1);
        
        int left=0,right=n-1,res=-1;
        
        while(left<=right)
        {
            int mid= left + (right-left)/2;
            
            if(nums[mid]==target)
            {
                if(mid==0)
                {
                    res=mid;
                    break;
                }
                else 
                {
                    if(nums[mid-1]==target)
                    {
                        right=mid-1;
                    }
                    else 
                    {
                        res=mid;
                        break;
                    }
                }
            }
            else if(nums[mid]>target)
            {
                right = mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        ans[0]=res;
        
        left=0;right=n-1;
        res=-1;
        
        while(left<=right)
        {
            int mid= left + (right-left)/2;
            
            if(nums[mid]==target)
            {
                if(mid==n-1)
                {
                    res=mid;
                    break;
                }
                else 
                {
                    if(nums[mid+1]==target)
                    {
                        left=mid+1;
                    }
                    else 
                    {
                        res=mid;
                        break;
                    }
                }
            }
            else if(nums[mid]>target)
            {
                right = mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        ans[1]=res;
        
        return ans;
    }
};