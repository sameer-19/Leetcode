class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> count(100000,0);
        
        int n=nums.size(),i,j;
        
        for(i=0;i<n;i++)
        {
            count[nums[i]+10000]++;
        }
        
        int cnt=0;
        
        for(i=100000-1;i>=0;i--)
        {
            if(count[i]>0)
            {
                cnt+=count[i];
                if(cnt>=k)
                {
                    return i-10000;
                }
            }
        }
        
        return -1;
    }
};