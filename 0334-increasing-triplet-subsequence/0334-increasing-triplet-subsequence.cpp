class Solution {
public:
    /*
    Brute- Three loops  - O(n^3)
    Better - Two loops + store the maximum element (form suffix max array) -  O(n^2)
    Optimal1 - Use two Arrays for storing the min and max of the whole array i.e.
                Make prefixMin and suffixMax arrays storing the min and max of prefix and                   suffix of the array. Now, traverse from index 1 to n-2 and 
                check if nums[i]>prefixMin[i-1] and nums[i]<suffixMax[i+1], 
                if yes, return true,
                else return false (after all traversal in the array)
                Time - O(n), space - O(n)
    Optimal2 - Take two numbers mn and mx for storing the min and max element. 
               Now, traverse in the array-> if nums[i]<=mn, then mn=nums[i],
               else if nums[i]<=mx, then mx=nums[i],
               else return true
               finally return false if true is not returned.
               Time - O(n) , space - O(1)
    */
    
    bool increasingTriplet(vector<int>& nums) {
        bool ans=false;
        
        int n=nums.size(),i;
        
        if(n<3) return false;
        
        int mn=INT_MAX,mx=INT_MAX;
        
        for(i=0;i<n;i++)
        {
            if(nums[i]<=mn) mn=nums[i];
            else if(nums[i]<=mx) mx=nums[i];
            else
            {
                return true;
            }
        }
        
        return false;
    }
};