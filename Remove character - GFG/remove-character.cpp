// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string s1, string s2) {
        int a[26]={0},b[26]={0};
        
        int i,m=s1.length(),n=s2.length();
        
        for(i=0;i<m;i++) a[s1[i]-'a']++;
        for(i=0;i<n;i++) b[s2[i]-'a']++;
        
        string ans="";
        for(i=0;i<26;i++)
        {
            if(a[i]>0 and b[i]==0)
            {
                a[i]=1; 
            }
            else a[i]=0;
        }
        
        for(i=0;i<m;i++)
        {
            if(a[s1[i]-'a']==1) ans+=s1[i];
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}
  // } Driver Code Ends