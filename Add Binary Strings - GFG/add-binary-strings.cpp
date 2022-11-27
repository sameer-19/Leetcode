//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    int m=a.length(),n=b.length();
	    
	    reverse(a.begin(),a.end());
	    reverse(b.begin(),b.end());
	    
	    string ans="";
	    
	    int carry=0;
	    
	    for(int i=0;i<min(m,n);i++)
	    {
	        int sum = (a[i]=='1') + (b[i]=='1');
	        sum+=carry;
	        if(sum==0)
	        {
	            ans+='0';   
	        }
	        else if(sum==1)
	        {
	            ans+='1';
	            carry=0;
	        }
	        else if(sum==2)
	        {
	            ans+='0';
	            carry=1;
	        }
	        else
	        {
	            ans+='1';
	            carry=1;
	        }
	    }
	    
	    int mn=min(m,n);
	    
	    if(mn==m)
	    {
	        for(int i=min(m,n);i<max(m,n);i++)
    	    {
    	        int sum = (b[i]=='1');
    	        sum+=carry;
    	        if(sum==0)
    	        {
    	            ans+='0';   
    	        }
    	        else if(sum==1)
    	        {
    	            ans+='1';
    	            carry=0;
    	        }
    	        else if(sum==2)
    	        {
    	            ans+='0';
    	            carry=1;
    	        }
    	        else
    	        {
    	            ans+='1';
    	            carry=1;
    	        }
    	    }
    	    
	    }
	    else
	    {
	        for(int i=min(m,n);i<max(m,n);i++)
    	    {
    	        int sum = (a[i]=='1');
    	        sum+=carry;
    	        if(sum==0)
    	        {
    	            ans+='0';   
    	        }
    	        else if(sum==1)
    	        {
    	            ans+='1';
    	            carry=0;
    	        }
    	        else if(sum==2)
    	        {
    	            ans+='0';
    	            carry=1;
    	        }
    	        else
    	        {
    	            ans+='1';
    	            carry=1;
    	        }
    	    }
	    }
	    
	    if(carry>0) ans+='1';
	    
	    while(ans.size()>0 and ans.back()=='0') ans.pop_back();
	    
	    reverse(ans.begin(),ans.end());
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends