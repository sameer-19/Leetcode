// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define lli long long int
class Solution {
  public:
    long long int commDiv(long long int a,long long int b) {
        lli i,ans=0;
        // cout<<d<<" ";
        vector<int> v1,v2;
        for(i=1;i*i<=a;i++)
        {
            if(a%i==0)
            {
                v1.push_back(i);
                if(i!=a/i) v1.push_back(a/i);
            }
        }
        
        for(i=1;i*i<=b;i++)
        {
            if(b%i==0)
            {
                v2.push_back(i);
                if(i!=b/i) v2.push_back(b/i);
            }
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        for(auto x: v1)
        {
            if(binary_search(v2.begin(),v2.end(),x)) ans++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int a, b;
        cin >> a >> b;
        Solution ob;
        cout<<ob.commDiv(a, b)<<endl;
    }
    return 0;
}
  // } Driver Code Ends