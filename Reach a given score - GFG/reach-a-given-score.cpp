// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function

long long dp[1001][3];

long long int solve(long long int n,int arr[],int i)
{
    if(n==0) return 1;
    
    if(n<0 || i==3) return 0;
    
    if(dp[n][i]!=-1) return dp[n][i];
    
    long long int a = solve(n-arr[i],arr,i);
    long long int b = solve(n,arr,i+1);
    
    return dp[n][i]=a+b;    
}

long long int count(long long int n)
{
    memset(dp,-1,sizeof(dp));
    int arr[3]={3,5,10};
    return solve(n,arr,0);
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends