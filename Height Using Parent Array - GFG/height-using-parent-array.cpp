// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> adj[100005];
    bool visited[100005]={false};
    
    int dfs(int id,int n,int h)
    {
        visited[id]=true;
        int mx=h;
        for(auto x: adj[id])
        {
            if(visited[x]==false)
            {
                mx=max(mx,dfs(x,n,h+1));
            }
        }
        return mx;        
    }
    
    int findHeight(int n, int arr[]){
        int i,idx=0;
        for(i=0;i<n;i++) 
        {
            if(arr[i]!=-1)
            {
                adj[arr[i]].push_back(i);
                adj[i].push_back(arr[i]);
            }
            else idx=i;
        }
        int ans=dfs(idx,n,1);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends