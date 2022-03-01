// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution{
    public:
    long long countPairs(int N, int X, vector<int> numbers){
        map<int , int > mp;
        for(auto e : numbers) mp[e]++;
        ll cnt = 0;
        for(auto e: mp ){
            int p = e.first;
            int q = X;
            bool f = true;
            while(p > 0){
                if( p%10 != q%10 ){
                    f= false;
                    break;
                }
                p/=10;
                q/=10;
            }
            if( !f) continue;
            if(q == e.first ){
                cnt+= (mp[q]*(mp[q]-1));
            }
            else{
                 cnt+=( mp[q]* e.second);
            }
        }
        return cnt;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends