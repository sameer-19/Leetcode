// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  vector<int> adj[1000];
  bool visited[1000];
  
  void solve(int node,int n)
  {
      visited[node]=true;
      for(auto x: adj[node])
      {
          if(!visited[x])
          {
                solve(x,n);
          }
      }
      return;
  }
  
    int biGraph(int arr[], int n, int e) {
        for(int i=0;i<2*e;i+=2)
        {
            adj[arr[i]].push_back(arr[i+1]);
            adj[arr[i+1]].push_back(arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            memset(visited,false,sizeof(visited));
            visited[i]=true;
            solve((i+1)%n,n);
            for(int j=0;j<n;j++) 
            {
                // cout<<"*";
                if(!visited[j]) return 0;
            }
            // cout<<"\n";
        }
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}  // } Driver Code Ends