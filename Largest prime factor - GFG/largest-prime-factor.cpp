//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    bool prime(int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0) return false;
        }
        
        return true;
    }

    long long int largestPrimeFactor(int N){
        long long int ans=2;
        
        for(int i=1;i*i<=N;i++)
        {
            if(N%i==0) 
            {
                if(prime(i))
                ans = max(ans,(long long int)i);
                if(prime(N/i)) ans = max(ans,(long long int)N/i);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends