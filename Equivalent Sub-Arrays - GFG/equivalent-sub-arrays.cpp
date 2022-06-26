// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n) {
       unordered_set<int> s(arr, arr+n);
       unordered_map<int, int> m;
       int i = 0, j = 0, count = 0;
       while(j < n) {
           m[arr[j]]++;
           while(i <= j && m.size() == s.size()) {
               count += n-j;
               if (--m[arr[i]] == 0) m.erase(arr[i]);
               i++;
           }
           j++;
       }
       return count;
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends