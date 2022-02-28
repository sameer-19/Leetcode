// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  double slope(pair<int,int> a,pair<int,int> b)
  {
      return (b.second-a.second)/(double)(b.first-a.first);
  }
  
    int mostBalloons(int n, pair<int, int> a[]) {
        if(n==1) return 1;
        int ans=INT_MIN,i,j;
        for(i=0;i<n;i++)
        {
            unordered_map<double,int> mp;
            int cnt=0;
            for(j=i+1;j<n;j++)
            {
                if(a[i]==a[j]) cnt++;
                else
                {
                    double val=slope(a[i],a[j]);
                    mp[val]++;
                }
            }
            for(auto x: mp)
            {
                ans=max(ans,x.second+cnt);
            }
        }
        return ans+1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends