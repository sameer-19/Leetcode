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
    map<int,int> mp;
    
    for(i=0;i<n;i++)
    {
        mp[a[i]]++;
        auto ptr=mp.find(a[i]);
        
        if(ptr==mp.begin()) ans.push_back(-1);
        else
        {
           auto x=prev(ptr,1);
           ans.push_back(x->first);
        }
    }
    return ans;
}