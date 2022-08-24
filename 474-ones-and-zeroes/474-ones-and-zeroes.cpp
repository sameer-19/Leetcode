class Solution {
public:
    bool check(int zeroes,int ones,string s)
    {
        int c0=0,c1=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0') c0++;
            else c1++;
        }
        
        return (c0<=zeroes && c1<=ones);
    }
    
    // DP Memoization
    int solve(int idx,int &zeroes,int &ones,vector<string> &a,
                                            vector<vector<vector<int>>> &dp)
    {
        if(idx==0)
        {
            if(check(zeroes,ones,a[idx]))
            {
                return 1;
            }
            return 0;
        }
        
        if(dp[idx][zeroes][ones]!=-1) return dp[idx][zeroes][ones];
        
        int notTake = solve(idx-1,zeroes,ones,a,dp);
        
        int take = 0;
        if(check(zeroes,ones,a[idx]))
        {
            int c0=0,c1=0;
            for(int i=0;i<a[idx].length();i++)
            {
                if(a[idx][i]=='0') c0++;
                else c1++;
            }
            zeroes-=c0;
            ones-=c1;
            take = 1 + solve(idx-1,zeroes,ones,a,dp);
            zeroes+=c0;
            ones+=c1;
        }
        
        return dp[idx][zeroes][ones] = max(take,notTake);
    }
    
    int findMaxForm(vector<string>& a, int m, int n) {
        int i,j;
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        
        for(auto x: a)
        {
            int zero = count(x.begin(),x.end(),'0');
            int one = x.length()-zero;
            
            for(i=m;i>=zero;i--)
            {
                for(j=n;j>=one;j--)
                {
                    dp[i][j]=max(dp[i][j],1+dp[i-zero][j-one]);
                }
            }
        }
        
        return dp[m][n];
    }
};