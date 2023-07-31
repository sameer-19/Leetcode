//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> pos,neg;
        int i=0;
        for(int j=0;j<n;j++) 
        {
            if(arr[j]>0) pos.push_back(arr[j]); else neg.push_back(arr[j]);
        }
        
        for(auto x: pos) arr[i++]=x;
        for(auto x: neg) arr[i++]=x;
        
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends