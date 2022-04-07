// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    int dp[M+1][V+1];
        for(int i=0;i<=M;i++)
        {
           for(int j=0;j<=V;j++)
           {
               if(j==0) dp[i][j]=0;
               if(i==0) dp[i][j]=INT_MAX-1;
           }
        }
        for(int i=1;i<M+1;i++)
        {
            for(int j=1;j<V+1;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[M][V]==INT_MAX-1) return -1;
        else return dp[M][V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends