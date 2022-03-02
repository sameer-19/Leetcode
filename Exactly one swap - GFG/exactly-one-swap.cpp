// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
#define lli long long int
class Solution
{
public:
    lli nc2(lli x)
    {
        return (x*(x-1))/2;
    }
    lli countStrings(string s)
    {
       lli n=s.length();
       map<char,lli> mp;
       for(auto x: s) mp[x]++;
       lli d=(n*(n-1))/2,f=0;
       for(auto x: mp)
       {
           if(x.second>1) 
           {
               f=1;
               d-=(nc2(x.second));
           }
       }
       if(f) d++;
       return d;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends