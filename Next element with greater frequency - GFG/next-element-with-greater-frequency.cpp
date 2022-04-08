// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        unordered_map<int,int> mp;
        int i,j;
        
        vector<int> ans(n);
        for(i=0;i<n;i++) ans[i]=-1;
        
        for(i=0;i<n;i++) mp[arr[i]]++;
        
        stack<pair<int,int>> s;
        
        for(i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                ans[i]=-1;
                s.push({arr[i],mp[arr[i]]});
            }
            else if(s.top().second>mp[arr[i]])
            {
                ans[i]=s.top().first;
                s.push({arr[i],mp[arr[i]]});
            }
            else
            {
                while(!s.empty() && s.top().second<=mp[arr[i]]) s.pop();
                if(s.empty())
                {
                    ans[i]=-1;
                }
                else
                {
                    ans[i]=s.top().first;
                }
                s.push({arr[i],mp[arr[i]]});
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}
  // } Driver Code Ends