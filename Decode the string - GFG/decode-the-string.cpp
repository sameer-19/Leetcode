//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        stack<int> count;
        stack<string> result;
        string res="";
        
        int index=0,n=s.length();
        
        while(index<n)
        {
            if(s[index]>='0' and s[index]<='9')
            {
                int cnt=0;
                while(s[index]>='0' and s[index]<='9')
                {
                    cnt = (cnt*10) + (s[index]-'0');
                    index++;
                }
                
                count.push(cnt);
            }
            else if(s[index]=='[')
            {
                result.push(res);
                res="";
                index++;
            }
            else if(s[index]==']')
            {
                int counter = count.top();
                count.pop();
                
                string ans = result.top();
                result.pop();
                
                for(int i=0;i<counter;i++)
                {
                    ans+=res;   
                }
                
                res=ans;
                index++;
                
            }
            else // s[index] is alphabet
            {
                res+=s[index];
                index++;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends