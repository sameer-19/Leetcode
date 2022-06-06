// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int k)
    {
        long long ans=0;
        
        int i;
        
        for(i=0;i<n;i++) A[i]=(A[i]%k);
        
        map<int,int> mp;
        
        
        // for(i=0;i<n;i++) cout<<A[i]<<" "; 
        
        for(i=0;i<n;i++) mp[A[i]]++;
        
        
        set<int> s;
        
        for(auto x: mp)
        {
            if(x.first==0)
            {
                int cnt=x.second;
                ans+=(cnt*(cnt-1))/2;
                s.insert(x.first);
            }
            else if(k-x.first==x.first)
            {
                int cnt=x.second;
                ans+=(cnt*(cnt-1))/2;
                s.insert(x.first);
            }
            else if(!s.count(x.first))
            {
                int cnt1=x.second,cnt2;
                cnt2=mp[k-x.first];
                
                ans+=(cnt1*cnt2);
                
                s.insert(x.first);
                s.insert(k-x.first);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends