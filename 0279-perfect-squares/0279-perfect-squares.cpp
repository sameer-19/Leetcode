class Solution {
public:
    int solve(int idx,vector<int> &a,int n,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(idx<0) return INT_MAX;
        
        if(dp[idx][n]!=-1) return dp[idx][n];
        
        int take = INT_MAX;
        
        if(a[idx]<=n)
        {
            take = 1 + solve(idx,a,n-a[idx],dp);
        }
        
        int notTake = solve(idx-1,a,n,dp);
        
        return dp[idx][n] = min(take,notTake);
    }
    
    int numSquares(int n) {
        vector<int> a;
        for(int i=1;i*i<=n;i++) a.push_back(i*i);
        
        int sz=a.size();
        
        vector<vector<int>> dp(sz,vector<int> (n+1,-1));
        
        int ans = solve(sz-1,a,n,dp);
    
        return ans;
    }
};