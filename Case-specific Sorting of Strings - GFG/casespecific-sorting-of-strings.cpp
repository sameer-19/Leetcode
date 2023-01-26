//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<char> upperCase,lowerCase;
        
        for(int i=0;i<n;i++)
        {
            if(str[i]>='A' and str[i]<='Z') upperCase.push_back(str[i]);
            else lowerCase.push_back(str[i]);
        }
        
        sort(upperCase.begin(),upperCase.end());
        sort(lowerCase.begin(),lowerCase.end());
        
        int i=0,j=0;
        
        for(int k=0;k<n;k++)
        {
            if(str[k]>='A' and str[k]<='Z') str[k] = upperCase[i++];
            else str[k] = lowerCase[j++];
        }
        
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends