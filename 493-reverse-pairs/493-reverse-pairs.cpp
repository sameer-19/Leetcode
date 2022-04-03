class Solution {
public:
    int merge(vector<int> &nums,int left,int mid,int right)
    {
        int rev_pair=0;
        int i=0,j=0;
        j=mid+1;
        for(i=left;i<=mid;i++){
            // int ct=0;
            while(j<=right && nums[i]>2LL * nums[j]) 
            {
                // ct++;
                j++;
            }
            
            rev_pair += (j-(mid+1));
        }
        
        
        vector<int> temp;
        i=left;j=mid+1;
        
        while(i<=mid && j<=right)
        {
            if(nums[i]<=nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=right){
            temp.push_back(nums[j]);
            j++;
        }
        for(i=left;i<=right;i++){
            nums[i]=temp[i-left];
        }
        return rev_pair;
    }
    
    int mergeSort(vector<int> &nums,int left,int right)
    {
        if(left>=right) return 0;
        
        int mid=left+(right-left)/2;
        
        int rev_pair=0;
        rev_pair += mergeSort(nums,left,mid);
        rev_pair += mergeSort(nums,mid+1,right);

        rev_pair += merge(nums,left,mid,right);
        
        return rev_pair;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};