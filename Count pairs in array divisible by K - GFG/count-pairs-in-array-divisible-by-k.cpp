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
        
        // map<int,int> mp;
        
        
        // for(i=0;i<n;i++) cout<<A[i]<<" "; 
        
        int mp[k+1]={0};
        bool visited[k+1]={0};
        
        for(i=0;i<n;i++) mp[A[i]]++;
        
        set<int> s;
        
        for(i=0;i<k;i++)
        {
            if(mp[i]>0)
            {
                if(i==0)
                {
                    int cnt=mp[i];
                    ans+=(cnt*(cnt-1))/2;
                    visited[i]=1;
                }
                else if(k-i==i)
                {
                    int cnt=mp[i];
                    ans+=(cnt*(cnt-1))/2;
                    visited[i]=1;
                }
                else if(visited[i]==0)
                {
                    int cnt1=mp[i],cnt2;
                    cnt2=mp[k-i];
                    
                    ans+=(cnt1*cnt2);
                    
                    visited[i]=1;
                    visited[k-i]=1;
                }   
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