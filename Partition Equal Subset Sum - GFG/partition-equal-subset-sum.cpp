// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve(int &sum,int arr[],int n,int idx,int target,int dp[][101])
    {
        if(idx==n)
        {
            if(sum==target) return 1;
            return 0;
        }
        if(sum>target) return dp[sum][idx] = 0;
        
        if(dp[sum][idx]!=-1) return dp[sum][idx];
        
        if(sum==target) return 1;
        
        sum+=arr[idx];
        int pick=solve(sum,arr,n,idx+1,target,dp);
        
        sum-=arr[idx];
        int notPick=solve(sum,arr,n,idx+1,target,dp);
        
        return dp[sum][idx]=(pick|notPick);
        
    }

    int equalPartition(int n, int arr[])
    {
        int sum=0,i;
        
        for(i=0;i<n;i++) sum+=arr[i];
        
        if(sum%2!=0) return 0;
        
        int target = sum/2;
       
       bool dp[n+1][target+1];
       
       for(int i = 0 ; i <= n ; i++) dp[i][0] = true;
       for(int j = 1 ; j <= target ; j++) dp[0][j] = false;
       
       for(int i = 1 ; i <= n ; i++) {
           for(int j = 1; j <= target; j++) {
               if(arr[i-1] > target) dp[i][j] = dp[i-1][j];
               else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
           }
       }
       return dp[n][target];
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends