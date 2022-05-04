// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    }
    
	return 0;
}// } Driver Code Ends

static bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first<b.first) return true;
    else if(a.first==b.first) 
    {
        if(a.second<b.second) return true;
        return false;
    }
    return false;
}


vector<int> permute(vector<vector<int>> &arr, int n)
{
    
    vector<int> ans;
    
    vector<pair<int,int>> v;
    int i;
    for(i=0;i<n;i++)
    {
        arr[i][0]+=arr[i][1];
        arr[i][1]=i+1;
        v.push_back({arr[i][0],arr[i][1]});
    }
    
    sort(v.begin(),v.end(),cmp);
    
    for(auto x: v) ans.push_back(x.second);
    
    return ans;
    
}