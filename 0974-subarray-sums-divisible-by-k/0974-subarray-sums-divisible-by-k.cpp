class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        
        int ans=0;
        int prefixSum=0;
        
        vector<int> modGroups(k,0);
        modGroups[0]=1;
        
        for(int &num: nums)
        {
            prefixSum=(prefixSum+(num%k)+k)%k;
            
            ans+=modGroups[prefixSum];
            modGroups[prefixSum]++;
        }
        
        return ans;
    }
};