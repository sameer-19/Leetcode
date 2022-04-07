// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string s[], int n)
    {
        int mn=INT_MAX,i,k;
        
        for(i=0;i<n;i++)
        {
            int z=s[i].length();
            mn=min(mn,z);
        }
        
        string ans="";
        
        for(k=0;k<mn;k++)
        {
            int a[26]={0},f=0;
            for(i=0;i<n;i++)
            {
                a[s[i][k]-'a']++;
            }
            for(i=0;i<26;i++) 
            {
                if(a[i]>0 && a[i]!=n) { f=1;break;}
            }
            if(f) break;
            ans+=s[0][k];
        }
        
        if(ans.length()>0) return ans;
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
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends