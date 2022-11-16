//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        int n=s.length();
        
        int ans=0;
        int a[26]={0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                a[s[j]-'a']++;
                int mx=0,mn=INT_MAX;
                for(int k=0;k<26;k++) 
                {
                    mx=max(mx,a[k]);
                    if(a[k]>0)
                    mn=min(mn,a[k]);
                }
                // cout<<mn<<" "<<mx<<endl;
                ans+=(mx-mn);
            }
            for(int k=0;k<26;k++) a[k]=0;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends