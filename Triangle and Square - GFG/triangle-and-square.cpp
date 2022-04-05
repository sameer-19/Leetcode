// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int countSquare(int n)
    {
	    if(n<=3) return 0;
	    if(n%2==0)
	    {
	        n/=2;
	        n--;
	        return ((n*n)+n)/2;
	    }
	    else{
	        n--;
	        n/=2;
	        n--;
	        return ((n*n)+n)/2;
	    }
    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int B,count;
    	cin>>B;
    	Solution ob;
    	count = ob.countSquare(B);
    	cout<<count<<endl;
    }
}  // } Driver Code Ends