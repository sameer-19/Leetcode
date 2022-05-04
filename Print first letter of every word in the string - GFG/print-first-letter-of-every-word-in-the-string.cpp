// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	string firstAlphabet(string s)
	{
	    string ans="";
	    int i,n=s.length(),f=0;
	    
	    for(i=0;i<n;i++)
	    {
	        if(f==0)
	        {
	            ans+=s[i];
	            f=1;
	        }
	        else if(s[i]==' ') 
	        {
	            f=0;
	        }
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	
        Solution ob;
   		cout << ob.firstAlphabet(s) << "\n";
   	}

    return 0;
} 
  // } Driver Code Ends