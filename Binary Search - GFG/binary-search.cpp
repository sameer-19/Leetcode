// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int a[], int n, int k) {
        
        int left=0,right=n-1;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(a[mid]==k) return mid;
            else if(a[mid]>k) right=mid-1;
            else left=mid+1;
        }
        
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}
  // } Driver Code Ends