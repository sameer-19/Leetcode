// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    int m=edges.size(),i,j;
	    
	    int d[n]={INT_MAX};
	    
	    for(i=0;i<n-1;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            int u=edges[j][0],v=edges[j][1],wt=edges[j][2];
	            
	            if(d[u]!=INT_MAX && d[u]+wt<d[v]) 
	            {
	                d[v]=d[u]+wt;
	            }
	            
	        }
	    }
	    
	    for(j=0;j<m;j++)
        {
            int u=edges[j][0],v=edges[j][1],wt=edges[j][2];
            
            if(d[u]!=INT_MAX && d[u]+wt<d[v]) 
            {
                d[v]=d[u]+wt;
                return true;
            }
        }
        
        return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends