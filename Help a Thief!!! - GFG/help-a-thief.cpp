// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        if(a.second>=b.second) return true;
        return false;
    }
  
  
    int maxCoins(int a[], int b[], int t, int n) {
        vector<pair<int,int>> v;
        
        int i,j,ans=0;
        
        for(i=0;i<n;i++)
        {
            v.push_back({a[i],b[i]});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        for(i=0;i<n;i++)
        {
            if(t>0)
            {
                if(t>=v[i].first)
                {
                    ans+=(v[i].first*v[i].second);
                    t-=v[i].first;
                }
                else
                {
                    ans+=(t*v[i].second);
                    t=0;
                }
            }
            else
            {
                break;
            }
        }
        
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends