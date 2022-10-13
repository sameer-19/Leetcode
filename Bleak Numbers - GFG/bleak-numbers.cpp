//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int count(int n)
    {
        int ans=0;
        while(n>0)
        {
            if(n&1) ans++;
            n=n>>1;
        }
        
        return ans;
    }

    int ceilLog(int n)
    {
        int ans=0;
        while(n>0)
        {
            ans++;
            n/=2;
        }
        
        return ans;
    }

	int is_bleak(int n)
	{
	    bool ok=true;
	    
	    for(int i=n-ceilLog(n);i<n;i++)
	    {
	        if(i+count(i)==n) 
	        {
	            ok=false;
	        }
	    }
	    
	    return ok;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends