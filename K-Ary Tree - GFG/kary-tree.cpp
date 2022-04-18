// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int power(long long x, unsigned int y, int p)
    {
        int res = 1;     // Initialize result
     
        x = x % p; // Update x if it is more than or
                    // equal to p
      
        if (x == 0) return 0; // In case x is divisible by p;
     
        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x) % p;
     
            // y must be even now
            y = y>>1; // y = y/2
            x = (x*x) % p;
        }
        return res;
    }
     
  
    long long karyTree(int k, int m) {
        int MOD=1e9+7;
        return power(k,m,MOD);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends