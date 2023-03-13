//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        int toto=0;
        long long ans=0;
        int mn=INT_MAX;
        for(int i=0;i<N;i++){
            ans+=B[i]%2!=0 ? A[i]*(--B[i]) : A[i]*B[i];
            if(B[i]>=2) mn=min(mn,A[i]);
            toto += B[i];
        }
        return toto%4==0 ? ans : ans-(2*mn);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends