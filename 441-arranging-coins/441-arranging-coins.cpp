class Solution {
public:
    int arrangeCoins(int n) {
        int left=1,right=1e9;
        int ans=1;
        
        while(left<=right)
        {
            long mid=left+(right-left)/2;
            long sum=(long)(mid*(mid+1))/2;
            if(sum<n) 
            {
                ans=mid;
                left=mid+1;
            }
            else if(sum==n)
            {
                return mid;
            }
            else
            {
                right=mid-1;
            }
        }
        
        return ans;
    }
};