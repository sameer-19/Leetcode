// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int findParent(int parent[], int x){
        if(parent[x] == x){
            return x;
        }
        else{
            parent[x] = findParent(parent , parent[x]);
            return parent[x];
        }
    }
    
    
    void union_( int a, int b, int parent[], int rank1[]) 
    {
        int a_rep = findParent(parent, a);
        int b_rep = findParent(parent, b);
        if(a_rep == b_rep){
            return;
        }
        if(rank1[a_rep] < rank1[b_rep]){
            parent[a_rep] = b_rep;
            return;
        }
        else if(rank1[b_rep] < rank1[a_rep]){
            parent[b_rep] = a_rep;
            return;
        }
        else{
            parent[a_rep] = b_rep;
            rank1[a_rep]++;
            return;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        return findParent(par, x) == findParent(par, y);
    }
};

// { Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends