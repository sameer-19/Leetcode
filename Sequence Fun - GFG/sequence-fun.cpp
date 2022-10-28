//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		int NthTerm(int n){
		    if(n==1) return 2;
		    if(n==2) return 5;
		    
		    int mod = (1e9)+7;
		    
		    long long prev=5;
		    for(int i=3;i<=n;i++)
		    {
		        prev=(((prev%mod)*(i%mod))%mod +1)%mod;
		    }
		    
		    return prev;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends