class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = 0;
        for(auto num: nums) totalOnes+= (num==1);
        
        int length = nums.size();
        
        int i=totalOnes, k = totalOnes, totalZeros = 0;
        
        for(int j=0;j<totalOnes;j++) totalZeros+=nums[j]==0;
        
        int ans = totalZeros;
        
        while(i<2*length)
        {        
            if(nums[i%length]==1) totalOnes++;
            else totalZeros++;
            
            if(nums[(i-k)%length]==0) totalZeros--;
            else totalOnes--;
            
            ans = min(ans,totalZeros);
            
            i++;
        }
        
        return ans;
    }
};