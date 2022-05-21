class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n=nums.size(),i;
        
        int low=0,mid=0,high=n-1;
        
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                int tmp=nums[low];
                nums[low]=nums[mid];
                nums[mid]=tmp;
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                int tmp=nums[high];
                nums[high]=nums[mid];
                nums[mid]=tmp;
                high--;
            }
        }
    }
};