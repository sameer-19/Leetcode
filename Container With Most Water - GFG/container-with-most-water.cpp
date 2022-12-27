//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long a[], int n)
{
    long long ans=0;
    
    int l=0,r=n-1;
    
    while(l<r)
    {
        long long cur = (r-l)*(min(a[l],a[r]));
        ans=max(ans,cur);
        
        if(a[l]<=a[r]) l++;
        else r--;
    }
    
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends