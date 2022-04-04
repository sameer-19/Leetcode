// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string previousNumber(string s){
        int n=s.length(),i;
        int id1=-1,id2=n-1;
        for(i=n-2;i>=0;i--)
        {
            if(s[i]>s[i+1]) { id1=i;break; }
        }
        if(id1==-1) { return "-1"; }
        for(i=n-1;i>id1;i--)
        {
            if(s[i]<s[id1]) {
                while(s[i]==s[i-1]) i--;
                
                id2=i;break;
            }
        }
        swap(s[id1],s[id2]);
        if(s[0]=='0') return "-1";
        return s;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends