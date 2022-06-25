// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    long long getAns(int cur, int* &c, int &n, int prev, vector<vector<int>>& adj){
        long long ans = c[cur-1] , maxans = 0, children = 0 ;
        for(auto &x: adj[cur]){
            if(x == prev)
                continue ;
            children++ ;
            long long tans = getAns(x,c,n,cur,adj) ;
            if(tans == -1)
                return -1 ;
            maxans = max(maxans,tans) ;
        }
        ans += children*maxans ;
        return ( ans > 1e18 ? -1 : ans ) ;
    }

    long long minimum_amount(vector<vector<int>> &edges, int n, int s, int *c){
        vector< vector<int> > adj(n+1) ;
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]) ;
            adj[e[1]].push_back(e[0]) ;
        }
        return getAns(s,c,n,-1,adj) ;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends