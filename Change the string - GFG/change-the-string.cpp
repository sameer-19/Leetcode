// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    char to_lower(char ch)
    {
        if(ch>='a' and ch<='z') return ch;
        
        char z='a';
        z+=(ch-'A');
        return z;
    }
    
    char to_upper(char ch)
    {
        if(ch>='A' and ch<='Z') return ch;
        
        char z='A';
        z+=(ch-'a');
        return z;
    }
    
    string modify (string s)
    {
        int low=0;
        
        int i,n=s.length();
        
        string ans="";
        ans+=s[0];
        
        if(s[0]>='a' and s[0]<='z') low=1;
        
        for(i=1;i<n;i++)
        {
            if(low)
            {
                ans+=to_lower(s[i]);
            }
            else ans+=to_upper(s[i]);
        }
        
        
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.modify (s) << endl;
	}
}  // } Driver Code Ends