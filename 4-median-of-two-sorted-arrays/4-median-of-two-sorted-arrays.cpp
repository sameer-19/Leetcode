class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // for applying the binary search on smaller sized array and reducing the time.
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        
        // boundary conditions for binary search - either 0 elements or all elements taken
        int left=0,right=nums1.size();
        
        int total=nums1.size()+nums2.size();
        
        int n1=nums1.size(),n2=nums2.size();
        // k/=2;
        
        while(left<=right)
        {
            int cut1= left + (right-left)/2;
//          cut2 represents the number of elements left to be taken to get median element
//          (n1+n2+1)/2 represents the total number of elements/2 of both the arrays to find the median at correct position
            int cut2= ((n1+n2+1)/2)-cut1;
            
//             Conditions for valid partition - l1<=r2 and l2<=r1
            
            int l1= cut1==0 ? INT_MIN : nums1[cut1-1];
            int l2= cut2==0 ? INT_MIN : nums2[cut2-1]; 
            int r1= cut1==nums1.size() ? INT_MAX : nums1[cut1];
            int r2= cut2==nums2.size() ? INT_MAX : nums2[cut2];
            
            if(l1<=r2 and l2<=r1)
            {
                if(total%2==0)
                {
                    return (max(l1,l2)+min(r1,r2))/2.0;   
                }
                else
                {
                    return max(l1,l2);
                }
            }
            else if(l1>r2)
            {
                right=cut1-1;    
            }
            else
            {
                left=cut1+1;
            }
        }
        
        return 0;
    }
};