// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    bool check(string s,int x)
    {
        int z=stoi(s);
        return (z%x==0);
    }

    string stringPartition(string s, int a, int b){
        string ans="";
        string first="",second="";
        
        int i,n=s.length();
        // first+=s[0];
        
        for(i=1;i<n;i++)
        {
            first=s.substr(0,i);
            second=s.substr(i);
            if(check(first,a) and check(second,b)) 
            {
                ans=first;
                ans+=" ";
                ans+=second;
                return ans;
            }
            
        }
        
        return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends