// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> arr){
        vector<int> ans;
        ans.push_back(-1);
        vector<int> sorted;
        sorted.push_back(n-1);
        for(int i = n-2;i>=0;i--){
            int low = 0;
            int high = sorted.size()-1;
            int temp = -1;
            while(low <= high){
                int mid = (low + high)/2;
                if(arr[sorted[mid]]>=arr[i]){
                    low = mid+1;
                }
                else{
                    temp = sorted[mid];
                    high = mid - 1;
                }
            }
            if(arr[sorted[sorted.size()-1]] > arr[i]){
                sorted.push_back(i);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends