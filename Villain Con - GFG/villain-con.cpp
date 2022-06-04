// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dfs(int node,vector<int>adj[],int t[]){
        if(t[node])
            return t[node];
        t[node] = 0;
        for(auto it:adj[node]){
                t[node] = max(t[node],dfs(it,adj,t));
        }
        t[node]+=1;
        return t[node];
    }
    int minColour(int N, int M, vector<int> mat[]) {
        vector<int>adj[N];
        for(int i=0;i<M;i++){
            adj[mat[i][1]-1].push_back(mat[i][0]-1);
        }
        int ans=-1;
        int t[N]={0};
        for(int i=0;i<N;i++){
            ans=max(ans,dfs(i,adj,t));
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends