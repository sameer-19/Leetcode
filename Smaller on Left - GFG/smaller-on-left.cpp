// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}// } Driver Code Ends


vector<int> Smallestonleft(int a[], int n)
{
    int i;
    vector<int> ans;
    set<int> s;
    
    for(i=0;i<n;i++)
    {
        auto it=s.lower_bound(a[i]);
        if(it==s.begin())
        {
            ans.push_back(-1);
        }
        else
        {
            it--;
            ans.push_back(*it);
        }
        s.insert(a[i]);
    }
    return ans;
}