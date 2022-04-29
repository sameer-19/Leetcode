// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// Driver program to test above function

 // } Driver Code Ends
class Solution{
  public:
    /*you are required to complete this method*/
    int convertFive(int n)
    {
        int ans=0;
        string s=to_string(n);
        for(int i=0;i<s.length();i++) 
        {
            if(s[i]=='0') s[i]='5';
        }
        ans=stoi(s);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	Solution obj;
    	cout<<obj.convertFive(n)<<endl;
    }
}  // } Driver Code Ends