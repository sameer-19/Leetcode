// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nthItem(int l1, int l2, int a[], int b[], int N)
    {
        set<int> s;
        int i,j;
        for(i=0;i<l1;i++) 
        {
            for(j=0;j<l2;j++) s.insert(a[i]+b[j]);
        }
        int cnt=0;
        for(auto x: s)
        {
            cnt++;
            if(cnt==N) return x;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int L1, L2, N;
        cin>>L1>>L2;
        int A[L1], B[L2];
        for(int i = 0;i < L1;i++)
            cin>>A[i];
        for(int i = 0;i < L2;i++)
            cin>>B[i];
        cin>>N;
        
        Solution ob;
        cout<<ob.nthItem(L1, L2, A, B, N)<<endl;
    }
    return 0;
}  // } Driver Code Ends