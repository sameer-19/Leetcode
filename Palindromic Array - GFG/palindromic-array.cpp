// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


 // } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    bool check(int x)
    {
        string s=to_string(x);
        
        for(int i=0;i<s.length()/2;i++)
        {
            if(s[i]!=s[s.length()-i-1]) return false;
        }
        return true;
    }

    int PalinArray(int a[], int n)
    {
    	int i;
    	
    	for(i=0;i<n;i++)
    	{
    	    if(!check(a[i])) return 0;
    	}
    	return 1;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}  // } Driver Code Ends