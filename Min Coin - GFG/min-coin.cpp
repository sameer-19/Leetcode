// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>a, int amt)
	{
	    int n=a.size();
	    vector<int> dp(amt+1,INT_MAX);
	    dp[0]=0;
	    int i,j;
	    
	    for(i=0;i<n;i++)
	    {
	        for(j=1;j<=amt;j++)
	        {
	            if(a[i]<=j && dp[j-a[i]]!=INT_MAX)
	            dp[j]=min(dp[j-a[i]]+1,dp[j]);
	        }
	    }
	    
	    return dp[amt]==INT_MAX?-1:dp[amt];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends