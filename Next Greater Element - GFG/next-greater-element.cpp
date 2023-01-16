//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

#define lli long long
class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<lli> ans(n,-1);
        stack<lli> s;
        
        for(int i=0;i<n;i++)
        {
            if(s.empty()) s.push(i);
            else if(arr[s.top()]<arr[i])
            {
                while(!s.empty() and arr[s.top()]<arr[i])
                {
                    ans[s.top()]=(arr[i]);
                    s.pop();
                }
                
                s.push(i);
            }
            else
            {
                s.push(i);
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
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends