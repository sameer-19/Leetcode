// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string remove(string s){
        string ans="";
        
        while(1)
        {
            int f=0;
            int i,n=s.length();
            for(i=0;i<n-1;i++)
            {
                if(s[i]!=s[i+1])
                {
                    ans+=s[i];
                }
                while(s[i]==s[i+1]) { i++; f=1;}
                
            }
            if(s[n-2]!=s[n-1]) ans+=s[i];
            
            if(f==0) break;
            s=ans;
            ans="";
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends