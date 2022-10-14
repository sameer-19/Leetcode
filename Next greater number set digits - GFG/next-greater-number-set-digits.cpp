//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int findNext (int N) 
    {
        string s = to_string(N);
        int n=s.length();
        int id1=-1,id2=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]<s[i+1]) 
            {
                id1=i;
                break;
            }
        }
        if(id1==-1) return -1;
        
        for(int i=n-1;i>id1;i--)
        {
            if(s[i]>s[id1]) 
            {
                id2=i;
                break;
            }
        }
        swap(s[id1],s[id2]);
        
        int left=id1+1,right=n-1;
        
        while(left<right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
        
        int ans = stoi(s);
        
        return ans;
    }  
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n; cin >> n;
		Solution ob;
		int res = ob.findNext (n);
		if (res == -1)
		    cout << "not possible";
		else
		    cout << res;
		cout << endl; 
	}
}
// } Driver Code Ends