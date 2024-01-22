class Solution {
    public int[] findErrorNums(int[] nums) {
        int size = nums.length;
        
        int[] arr = new int[size];
        
        for(int i=0;i<size;i++)
        {
            arr[nums[i]-1]++;
        }
        
        int[] ans = new int[2];
        
        for(int i=0;i<size;i++)
        {
            if(arr[i]==2) ans[0] = i+1;
            else if(arr[i]==0) ans[1] = i+1;
        }
        
        return ans;
    }
}