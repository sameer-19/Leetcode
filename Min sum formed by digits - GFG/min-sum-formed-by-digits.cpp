// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    typedef long long int lli;
    public:
    long long int minSum(int arr[], int n)
    {
        lli a=0,b=0,i;
        
        sort(arr,arr+n);
        
        for(i=0;i<n;i++)
        {
            if(i%2==0) 
            {
                a*=10;
                a+=arr[i];
            }
            else
            {
                b*=10;
                b+=arr[i];
            }
        }
        
        return a+b;
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends