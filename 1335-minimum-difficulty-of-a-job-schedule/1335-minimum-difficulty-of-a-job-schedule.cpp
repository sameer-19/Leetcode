class Solution {
public:
    
    int solve(int idx,int days,int n,vector<int> &jobd,vector<vector<int>> &dp)
    {
        if(days==1)
        {
            int mx=INT_MIN;
            for(int j=idx;j<n;j++) mx=max(mx,jobd[j]);
            
            return mx;
        }
        
        if(dp[idx][days]!=-1) return dp[idx][days];
        int result=INT_MAX;
        int curMax=INT_MIN;
        
        for(int i=idx;i<=n-days;i++)
        {
            curMax = max(curMax,jobd[i]);
            result = min(result,curMax + solve(i+1,days-1,n,jobd,dp)); 
        }
        
        return dp[idx][days] = result;
    }
    
    int minDifficulty(vector<int>& jobd, int d) {
        int n=jobd.size();
        if(n<d) return -1;
        else if(n==d)
        {
            int ans=0;
            for(int i=0;i<n;i++) ans+=jobd[i];
            return ans;
        }
        else
        {
            vector<vector<int>> dp(n,vector<int> (d+1,-1));
            return solve(0,d,n,jobd,dp);
        }
    }
};