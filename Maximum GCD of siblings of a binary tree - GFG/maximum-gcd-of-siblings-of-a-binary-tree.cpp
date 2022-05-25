// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> arr, int n) {
        vector<int> adj[100005];
        int i,j;
        
        for(auto x: arr)
        {
            adj[x[0]].push_back(x[1]);
            // adj[x[1]].push_back(x[0]);
        }
        
        // for(i=1;i<1e5+5;i++)
        // {
        //     if(adj[i].size()>0)
        //     {
        //         for(j=0;j<adj[i].size();j++) cout<<adj[i][j]<<" ";
        //         cout<<endl;
        //     }
        // }
        if(n==1) return 0;
        
        int ans=1,mx=1,f=0;
        for(i=1;i<1e5+5;i++)
        {
            mx=0;
            int cnt=0;
            for(auto x: adj[i])
            {
                if(mx==0) mx=x;
                else mx=__gcd(mx,x);
                cnt++;
            }
            // if(mx>0) cout<<mx<<" ";
            if(cnt>1) ans=max(ans,mx),f=1;
        }
        if(f) return ans;
        return 0;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends