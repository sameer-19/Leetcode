class Solution {
public:
    int MOD = (int)1e9+7;
    
    int solve(int idx,int target,int &k,vector<vector<int>> &dp)
    {
        if(idx==0)
        {
            if(target==0) return 1;
            return 0;
        }
        
        if(target<=0) return 0;
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        int ans=0;
        
        for(int i=1;i<=k;i++)
        {
            ans+=solve(idx-1,target-i,k,dp);   
            ans%=MOD;
        }
        
        return dp[idx][target] = ans%MOD;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        
        return solve(n,target,k,dp);
    }
};