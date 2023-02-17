//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> arr) {
        if(k==n) return arr[k-1];
        
        long long ans=0,sum=0;
        
        for(long long &x: arr) sum+=x;
        
        for(int i=0;i<(n-k);i++)
        {
            arr.push_back(sum);
            sum-=arr[i];
            sum+=arr[arr.size()-1];
        }
        ans=arr[arr.size()-1];
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends