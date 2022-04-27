// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> getMoreAndLess(int arr[], int n, int x) {
	    int low=0,high=n-1;
	    
	    if(arr[0]>x) return {0,n};
	    else if(arr[n-1]<x) return {n,0};
	    
	    int ans=0,i;
	    while(low<=high)
	    {
	        int mid=low+(high-low)/2;
	        if(arr[mid]>x) high=mid-1;
	        else
	        {
	            ans=max(ans,mid);
	            low=mid+1;
	        }
	    }
	    int cnt=0,tp=ans;
	    while(tp>=0 and arr[tp]==x) cnt++,tp--;
	    vector<int> v;
	    v.push_back(ans+1);
	    v.push_back(n-ans-1 + cnt);
	    return v;
	    
	   // return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMoreAndLess(arr, n, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
  // } Driver Code Ends