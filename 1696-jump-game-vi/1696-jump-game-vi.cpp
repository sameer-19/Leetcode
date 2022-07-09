class Solution {
public:
    
    int solve(vector<int>& nums,int idx,int k,vector<int>& dp)
    {
        if(idx<0) return 0;
        
        if(idx==0)
        {
            return nums[0];
        }
        
        if(dp[idx]!=-1e9) return dp[idx];
        
        int maxi=-1e9;
        
        for(int i=idx-1;i>=0 and i>=idx-k;i--)
        {
            int temp = solve(nums,i,k,dp);
            
            maxi=max(maxi,temp);
            
        }
        
        return dp[idx] = nums[idx]+maxi;
    }
    
    
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(size(nums), INT_MIN);
        
        multiset<int> s ({ dp[0] = nums[0] });         
        // set dp[0] = nums[0] and insert it into set
        
        for(int i = 1; i < size(nums); i++) 
        {
            if(i > k) s.erase(s.find(dp[i - k - 1])); 
            // erase elements from which we cant jump to current index
            
            s.insert(dp[i] = *rbegin(s) + nums[i]);    
            // choose element with max score and jump from that to the current index
            
        }
        
        return dp.back();
    }
};