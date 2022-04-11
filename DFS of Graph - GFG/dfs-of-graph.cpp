// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  
  void dfs(int node,int V,vector<int> adj[],vector<int> &ans,bool visited[])
  {
      visited[node]=true;
      
      ans.push_back(node);
      
      for(auto x: adj[node])
      {
          if(!visited[x]) dfs(x,V,adj,ans,visited);
      }
      return;
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        bool visited[100001]={false};
        
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i]) dfs(i,V,adj,ans,visited);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends