//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> a, int n) {
        sort(a.begin(),a.end());
        
        long long int ans=0;
        
        // int cur=0;
        
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
            {
                ans++;
                a[i]++;
            }
            else if(a[i]<a[i-1])
            {
                ans+=a[i-1]-a[i];
                a[i]=a[i-1]+1;
                ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends