// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    sort(a,a+n);
    
    vector<int> ans(n);
    
    int i=0,j=0;
    
    for(i=n-1;i>=0 and j<n;i--) 
    {
        ans[j]=a[i];
        j+=2;
    }
    
    j=1;
    for(int k=0;k<=i and j<n;k++)
    {
        ans[j]=a[k];
        j+=2;
    }
    
    int sum=0;
    for(i=0;i<n;i++)
    {
        if(i%2==0) sum+=ans[i];
        else sum-=ans[i];
        if(sum==0) return {-1};
    }
    
    // for(i=0;i<n;i++)
    //     ans.push_back(a[i]);
    
    return ans;
}
