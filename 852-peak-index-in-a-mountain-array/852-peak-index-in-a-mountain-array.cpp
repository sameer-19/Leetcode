class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int ans=0,n=a.size();
        
        int left=0,right=n-1;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            
            if(mid==0)
            {
                left=mid+1;   
            }
            else if(mid==n-1)
            {
                right=mid-1;
            }
            else if(a[mid-1]<a[mid] and a[mid]>a[mid+1]) return mid;
            else if(a[mid-1]<a[mid] and a[mid]<a[mid+1]) left=mid+1;
            else right=mid-1;
        }
        return 1;
    }
};