// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> arr, int n) {
        int i,j;
        
        sort(arr.begin(),arr.end());
        
        if(n==1) return 0;
        
        int cur=0,ans=0,prev=arr[0][0],cnt=1;
        
        for(i=1;i<arr.size();i++)
        {
            if(i==1) cur=arr[0][1];
            if(arr[i][0]==prev) cur=__gcd(cur,arr[i][1]),cnt++;
            else{
                if(cnt>1)
                {
                    ans=max(ans,cur);
                }
                cur=arr[i][1];
                prev=arr[i][0];
                cnt=1;
            }
        }
        
        if(cnt>1)
        ans=max(ans,cur);
        return ans;
        // return 0;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends