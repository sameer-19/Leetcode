//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int h[], int N) {
        vector<int> dp;
        int ans=1;
        
        dp.push_back(h[0]);
        
        for(int i=1;i<N;i++)
        {
            if(h[i]>dp.back())
            {
                dp.push_back(h[i]);
            }
            else
            {
                auto x = lower_bound(dp.begin(),dp.end(),h[i])-dp.begin();
                dp[x] = h[i];
            }
        }
        
        ans=dp.size();
        
        return N-ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends