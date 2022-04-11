// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int node,int V,vector<int> adj[],bool visited[],vector<int> &ans)
    {
        queue<int> q;
        q.push(node);
        
        ans.push_back(node);
        
        while(!q.empty())
        {
            int root=q.front();
            q.pop();
            
            for(auto it: adj[root])
            {
                if(!visited[it])
                {
                    visited[it]=true;
                    
                    ans.push_back(it);
                    
                    q.push(it);
                }
            }
        }
        return;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
        bool visited[10005]={false};
        
        bfs(0,V,adj,visited,ans);
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends