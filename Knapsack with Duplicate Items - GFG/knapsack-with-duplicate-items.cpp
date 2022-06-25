// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    int solve(int W,int N,int i,int wt[],int val[])
    {
        if(W==0 || i==-1)
        {
            // ans=max(ans,profit);
            return 0;
        }
        
        if(dp[W][i]!=-1) return dp[W][i];
        
        int left=-1,right=-1;
        
        if(W>=wt[i])
        {
            left = val[i]+solve(W-wt[i],N,i,wt,val);
        }
        
        right = solve(W,N,i-1,wt,val);
        
        return dp[W][i]=max(left,right);
    }

    
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(W,N,N-1,wt,val);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends