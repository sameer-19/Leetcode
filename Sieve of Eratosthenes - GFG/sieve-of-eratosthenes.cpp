// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        vector<int> ans;
        
        int i,j;
        
        bool a[10005]={false};
        
        a[0]=true; a[1]=true;
        
        for(i=2;i<=n;i++)
        {
            if(!a[i])
            {
                ans.push_back(i);
                for(j=i*i;j<=n;j+=i) a[j]=true;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends