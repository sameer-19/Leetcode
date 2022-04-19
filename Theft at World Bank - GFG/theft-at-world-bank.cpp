// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long double maximumProfit(int n, long long W, vector<long long> w, vector<long long> p){
	    long double ans=0;
	    long i,j;
	    
	    vector<pair<double,pair<long long,long long>>> v;
	    
	    for(i=0;i<n;i++)
	    {
	        v.push_back({(double)p[i]/w[i],{p[i],w[i]}});
	    }
	    
	    sort(v.begin(),v.end());
	    reverse(v.begin(),v.end());
	    
	    for(i=0;i<n && W>0;i++)
	    {
	        long long rt=sqrt(v[i].second.second);
            if(rt*rt!=v[i].second.second)
            {
                if(W>=v[i].second.second)
	            {
	                ans+=v[i].second.first;
	                W-=v[i].second.second;
	            }
	            else
	            {
	                ans+=(long double)((long double)v[i].second.first/v[i].second.second)*W;
	                W=0;
	            }
            }
	    }
	    
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends