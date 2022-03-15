// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int count(int n, vector<int> a,int x)
    {
        int ans=INT_MAX;
        int mask=0;
        for(int i=31;i>=0;i--)
        {
            if((x>>i) & 1)
            {
                mask|=(1ll<<i);
                continue;
            }
            int cnt=0;
            int temp=mask|(1ll<<i);
            for(int i=0;i<n;i++)
            {
                if((a[i] & temp) ==temp)
                {
                    cnt++;
                }
            }
            ans=min(ans,n-cnt);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends