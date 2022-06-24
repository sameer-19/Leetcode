class Solution {
public:
    int solve(vector<int>& a,int mid)
    {
        int n=a.size(),i,sum=0;
        
        for(i=0;i<n;i++) sum+=min(a[i],mid);
        
        return sum;
    }
    
    int findBestValue(vector<int>& arr, int target) {
        int i,n=arr.size();
        
        int left=0,right=*max_element(arr.begin(),arr.end());
        
        int left_diff=INT_MAX,right_diff=INT_MAX;
        int left_best,right_best;
        
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            
            int total = solve(arr,mid);
            
            if(total<target)
            {
                if(abs(total-target)<left_diff)
                {
                    left_diff=abs(total-target);
                    left_best=mid;
                }
                left=mid+1;
            }
            else
            {
                if(abs(total-target)<right_diff)
                {
                    right_diff=abs(total-target);
                    right_best=mid;
                }
                right=mid-1;
            }
        }
        
        return (left_diff<=right_diff) ? left_best : right_best;
    }
};