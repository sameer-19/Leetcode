// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long helper(int n,int r){
       if(r > n) return (0);
       if(r > n - r) r = n - r;
       
       int dp[r+1];
       for(int i = 0; i <= r; i++) dp[i] = 0;
       dp[0] = 1;
       
      for(int i = 1; i <= n; i++){
           for(int j = min(i,r); j > 0; j--){
               dp[j] = (dp[j] + dp[j-1]) * 1LL;
           }
       }
       
       return (dp[r]);
   }
   
   long posIntSol(string s){
       int size = s.length();
       
       string temp{};
       int i = size-1;
       while(s[i] != '=') temp = s[i] + temp, i--;
       
       int n = stoi(temp) - 1;
       int r = (size - temp.size()) / 2 - 1;
       
       return (helper(n,r));
   }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends