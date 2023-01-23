//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string a) {
        stack<char> s;
        
        int n=a.length();
        
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            if(s.empty()) s.push(a[i]);
            else if(s.top()==a[i]) s.pop();
            else s.push(a[i]);
        }
        
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        
        return (ans.length()>0) ? ans : "-1";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends