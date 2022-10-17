//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> a)
	{
		vector<int> ans;
		
		int i,j,k;
		
		for(i=0;i<n;i++)
		{
		    j=0;k=i;
		    while(j<n and k>=0)
		    {
		        ans.push_back(a[j++][k--]);
		    }
		}
		
		for(i=1;i<n;i++)
		{
		    j=i;k=n-1;
		    while(j<n and k>=0) ans.push_back(a[j++][k--]);
		}
		
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends