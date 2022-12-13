//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int check(int mid,int arr[],int n)
    {
        int sum=0,cnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(sum+arr[i]<=mid)
            {
                sum+=arr[i];
            }
            else
            {
                cnt++;
                sum=arr[i];
            }
        }
        
        return cnt+1;
    }
  
    int splitArray(int arr[] ,int n, int k) {
        int sum=0,mx=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            mx=max(mx,arr[i]);
        }
        
        int left=mx,right=sum;
        
        int ans=0;
        
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            
            if(check(mid,arr,n)<=k)
            {
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends