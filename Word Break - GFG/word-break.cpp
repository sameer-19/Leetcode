// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string s, vector<string> &arr) {
        
        int n=s.length();
        
        int dp[n+1]={0};
        dp[n]=1; // true for empty string
        
        unordered_set<string> dict;
        
        for(auto x: arr) dict.insert(x); 
        
        for(int i=n-1;i>=0;i--)
        {
            string word;
            for(int j=i;j<n;j++)
            {
                word.push_back(s[j]);
                
                if(dict.find(word)!=dict.end())
                {
                    if(dp[j+1]) dp[i]=1;
                }
            }
        }
        
        return dp[0];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends