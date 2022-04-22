// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int sum(int a , int b)
    {
        int res = 0, c = 0;
        for(int i=0; i<31; i++) {
            int bit = 1<<i, curr = 0;
            if(c == 1) {
                if(a&bit && b&bit) curr = 1;
                else if(!(a&bit) && !(b&bit)) curr = 1, c = 0;
            } else {
                if(a&bit && b&bit) c = 1;
                else if(a&bit || b&bit) curr = 1;
            }
            if(curr) res |= (1<<i);
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends