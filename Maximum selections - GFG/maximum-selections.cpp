// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// ranges[i][0] is the start of ith range
// ranges[i][1] is the end of ith range

class Solution{
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }

    int max_non_overlapping( vector< vector<int> >& a )
    {
         sort(a.begin(),a.end(),cmp);
         int ans=1;
         vector<int> prev=a[0];
         int i=1,n=a.size();
         
         while(i<n)
         {
             if(a[i][0]>=prev[1]) 
             {
                 ans++;
                 prev=a[i];
             }
             i++;
         }
         return ans;
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

		vector< vector<int> > v(n,vector<int>(2));
		for(int i=0; i<n; i++)
			cin>> v[i][0] >> v[i][1];
			
        Solution ob;
		cout<< ob.max_non_overlapping(v) << endl;
	}
	return 1;
}

  // } Driver Code Ends