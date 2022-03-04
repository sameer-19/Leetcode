// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    bool solve(int a,int b,int c)
    {
        if(a+b<=c) return false;
        if(b+c<=a) return false;
        if(a+c<=b) return false;
        return true;
    }
    
    vector<int> canMakeTriangle(vector<int> a, int n){
        vector<int> ans(n-2);
        int i;
        for(i=0;i<n-2;i++)
        {
            if(solve(a[i],a[i+1],a[i+2])) ans[i]=1;
            else ans[i]=0;
        }
        return ans;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends