// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool solve(int cur,int n,int k,int m,vector<int>& a)
    {
        if(cur>=n) return 1;
        if(n-cur<k) return 0;
        for(int i=cur+k-1;i<n;i++)
        {
            if(a[i]-a[cur]>m) return 0;
            if(solve(i+1,n,k,m,a)) return 1;
        }
        return 0;
    }
    
    bool partitionArray(int n, int k, int m, vector<int> &a){
        sort(a.begin(),a.end());
        
        if(a[n-1]-a[0]<=m) return true;
        
        return solve(0,n,k,m,a);
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends